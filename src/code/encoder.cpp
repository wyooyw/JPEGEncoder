#include <stdio.h>
#include <fstream>
#include <iostream>
#include<math.h>
#include "Bits.h"
#include "BitsMerger.h"
#include "BitsWriter.h"
#include "EncodeTable.h"
#include "ImageInput.h"
#include "RLEEncoder.h"
#include "BITEncoder.h"
#include "HuffmanEncoder.h"
#include "JPEGEncoder.h"
#include "HuffmanTable.h"

#define PI 3.1415926
using namespace std;

int COMPRESS_RATE;
void changeQuantizeMat(int *quantizeMat) {
	if (COMPRESS_RATE == 0) {
		for (int i = 0; i < 64; i++) {
			*quantizeMat++ = 1;
		}
	}
	else {
		for (int i = 0; i < 64; i++) {
			//*quantizeMat = max(1, *quantizeMat/2);
			//quantizeMat++;
			*quantizeMat++ *= COMPRESS_RATE;
		}
	}
	
}

void printMat(int w,int h,double *mat) {
	int total = w * h;
	for (int i = 0; i < total; i++) {
		if ((i % w) == 0) {
			printf("\n");
		}
		printf("%.4f ",mat[i]);
	}
	printf("\n");
}

void printIntMat(int w, int h, int* mat) {
	int total = w * h;
	for (int i = 0; i < total; i++) {
		if ((i % w) == 0) {
			printf("\n");
		}
		printf("%d\t", mat[i]);
	}
	printf("\n");
}

//输入:r,g,b  输出:y,cb,cr
void RGB2YUV(int w,int h,double *src,double *dst) {
	int total = w * h;
	double* r = src;
	double* g = src + total;
	double* b = src + total + total;
	double* y = dst;
	double* cb = dst+total;
	double* cr = dst+total+total;

	for (int i = 0; i < total; i++) {
		*y = (0.299 * (*r) + 0.587 * (*g) + 0.114 * (*b)) - 128;
		*cb = (-0.1687 * (*r) - 0.3313 * (*g) + 0.5 * (*b));
		*cr = (0.5 * (*r) - 0.4187 * (*g) - 0.0813 * (*b));

		y++;
		cb++;
		cr++;

		r++;
		g++;
		b++;
	}
}
	
void split(int w, int h, double* src, double* dst) {
	if (w % 8 || h % 8) {
		printf("w and h must divide exactly by 8!");
		return;
	}
	for (int j = 0; j < h; j += 8) {
		for (int i = 0; i < w; i += 8) {
			//第i/8行第j/8列的块
			for (int v = 0; v < 8; v++) {
				for (int u = 0; u < 8; u++) {
					*(dst++) = *(src + (j + v) * w + (i + u));
				}
			}
		}
	}
}

void sequenceZ(int* src, int* dst) {
	int* p = src;
	int x = 0, y = 0, state = 0;//0:左下；1：右上
	while (true) {
		*dst++ = *p;
		if (x == 0 && y == 0) {
			p++;
			x++;
		}
		else if (x==7 && y==7) {
			break;
		}
		else if (state==0) {
			//向左下
			if (y == 7) {
				p++;
				x++;
				state = 1;
			}
			else if (x == 0) {
				p += 8;
				y++;
				state = 1;
			}
			else {
				p += 7;
				x--;
				y++;
			}
		}
		else {
			//向右上
			if (x == 7) {
				p += 8;
				state = 0;
				y++;
			}
			else if (y == 0) {
				p++;
				state = 0;
				x++;
			}
			else {
				p -= 7;
				x++;
				y--;
			}
		}
	}
}

void DCT(double* src, double* dst) {
	double a2 = 0.5;
	double a1 = sqrt(1 / 8.0);
	for (int i = 0; i < 8; i++) {
		dst[i] = 0;
		for (int j = 0; j < 8; j++) {
			dst[i] += src[j]*cos(PI / 8 * i * (j + 0.5));
		}
		if (i == 0) {
			dst[i] *= a1;
		}
		else {
			dst[i] *= a2;
		}
	}
}

//转置
void transpose(double* src) {
	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 8; j++) {
			//double t = src[i][j];
			//src[i][j] = src[j][i];
			//src[j][i] = t;
			double t = *(src + i * 8 + j);
			*(src + i * 8 + j) = *(src + j * 8 + i);
			*(src + j * 8 + i) = t;
		}
	}
}

//二维离散余弦变换
void DCT2D(double* src, double* dst) {
	double* middle = (double*)malloc(sizeof(double) * 8 * 8);
	for (int i = 0; i < 8; i++) {
		DCT(dst+i*8, middle +i*8);
	}
	
	transpose(middle);

	for (int i = 0; i < 8; i++) {
		DCT(middle + i * 8, dst + i * 8);
	}

	transpose(dst);
}



//量化
void quantize(double* src,int *qTable,int *dst) {
	for (int i = 0; i < 64; i++) {
			*dst++ = (int)round(*src++ / *qTable++);
	}
}

void printList(list<int> l) {
	list<int>::iterator iter = l.begin();
	for (iter == l.begin(); iter != l.end(); iter++) {
		printf("%d ", *iter);
	}
	printf("\n");
}
int main() {


	char _path[500];
	string path,in_path, out_path, qtable_path, qtableC_path;
	printf("请输入工作文件夹的路径(以/或\\结尾)：");
	getline(cin, path, '\n');
	
	in_path = path + "image.txt";
	out_path = path + "output.jpeg";
	qtable_path = path + "qtable.txt";
	qtableC_path = path + "qtableC.txt";
	printf("%s\n", in_path.data());
	printf("%s\n", out_path.data());
	printf("%s\n", qtable_path.data());
	printf("%s\n", qtableC_path.data());
	
	double* rgb;
	int h, w;
	//1.读取图片
	ImageInput inputer;
	inputer.readImage(in_path.data(),&rgb,&w,&h);
	if ((w % 8) || (h % 8)) {
		printf("长宽应是8的倍数");
		return 0;
	}

	printf("请输入压缩比例：");
	scanf("%d", &COMPRESS_RATE);
	printf("%d", COMPRESS_RATE);

	/*
	printf("---RGB begin---\n");
	printMat(w, h, rgb);
	printf("---RGB end---\n");
	*/

	//2.rgb转yuv
	
	double* yuv = (double*)malloc(sizeof(double) * w * h * 3);
	RGB2YUV(w, h, rgb, yuv);
	free(rgb);
	
	/*
	printf("---YUV begin---\n");
	printMat(8, 8, yuv+256*256);
	printf("----\n");
	printMat(8, 8, yuv + 256 * 256 + w * h);
	printf("----\n");
	printMat(8, 8, yuv + 256 * 256 + 2*w * h);
	printf("---YUV end---\n");
	*/
	
	//3.分割8*8小块
	double* split_y = (double*)malloc(sizeof(double) * w * h);
	double* split_u = (double*)malloc(sizeof(double) * w * h);
	double* split_v = (double*)malloc(sizeof(double) * w * h);
	
	split(w, h, yuv, split_y);
	split(w, h, yuv+w*h, split_u);
	split(w,h,yuv+2*w*h, split_v);
	
	free(yuv);
	
	//4.DCT
	int block_nums = w * h / 8 / 8;
	for (int i = 0; i < block_nums; i++) {
		DCT2D(split_y+(i<<6), split_y + (i << 6));
		DCT2D(split_u + (i << 6), split_u + (i << 6));
		DCT2D(split_v + (i << 6), split_v + (i << 6));
		
	}
	printf("a");
	/*
	printf("---DCT begin---\n");
	printMat(8, 8, split_y);
	printf("------\n");
	printMat(8, 8, split_u);
	printf("------\n");
	printMat(8, 8, split_v);
	printf("------\n");
	printf("---DCT end---\n");
	*/
	
	
	//5.量化
	int* qTable,*qTableC;
	//inputer.readQTable("D://qtable.txt", &qTable);
	//inputer.readQTable("D://qtableC.txt", &qTableC);
	inputer.readQTable(qtable_path.data(), &qTable);
	inputer.readQTable(qtableC_path.data(), &qTableC);
	changeQuantizeMat(qTable);
	changeQuantizeMat(qTableC);
	int* split_y_q = (int*)malloc(sizeof(int) * w * h);
	int* split_u_q = (int*)malloc(sizeof(int) * w * h);
	int* split_v_q = (int*)malloc(sizeof(int) * w * h);
	for (int i = 0; i < block_nums; i++) {
		quantize(split_y + (i << 6), qTable, split_y_q + (i << 6));
		quantize(split_u + (i << 6), qTableC, split_u_q + (i << 6));
		quantize(split_v + (i << 6), qTableC, split_v_q + (i << 6));
		
	}
	free(split_y);
	free(split_u);
	free(split_v);

	//printIntMat(w, h, split_y_q);
	//printIntMat(w, h, split_u_q);
	//printIntMat(w, h, split_v_q);

	printf("b");
	//6.排列
	int* split_y_z = (int*)malloc(sizeof(int) * w * h);
	int* split_u_z = (int*)malloc(sizeof(int) * w * h);
	int* split_v_z = (int*)malloc(sizeof(int) * w * h);
	for (int i = 0; i < block_nums; i++) {
		sequenceZ(split_y_q + (i << 6), split_y_z + (i << 6));
		sequenceZ(split_u_q + (i << 6), split_u_z + (i << 6));
		sequenceZ(split_v_q + (i << 6), split_v_z + (i << 6));
		
	}
	free(split_y_q);
	//printIntMat(64, 1, split_y_z);
	
	printIntMat(64, 1, split_y_z);
	
	
	//7.RLE编码和BIT编码
	RLEEncoder rleEncoder_y, rleEncoder_u, rleEncoder_v;
	BITEncoder bitEncoder;

	HuffmanTable huffmanTable;

	list<list<BITNode> > BitNodeList_y;
	list<list<BITNode> > BitNodeList_u;
	list<list<BITNode> > BitNodeList_v;

	printf("BITNODE-Y start\n");
	for (int i = 0; i < block_nums; i++) {
		list<RLENode> rleNodeList = rleEncoder_y.encode(split_y_z + (i << 6));
		
		list<BITNode> bitNodeList = bitEncoder.encode(rleNodeList);

		BitNodeList_y.push_back(bitNodeList);
	}
	printf("BITNODE-Y end\n");
	printf("BITNODE-U start\n");
	for (int i = 0; i < block_nums; i++) {
		list<RLENode> rleNodeList = rleEncoder_u.encode(split_u_z + (i << 6));
		
		list<BITNode> bitNodeList = bitEncoder.encode(rleNodeList);

		
		BitNodeList_u.push_back(bitNodeList);
	}
	printf("BITNODE-U end\n");
	for (int i = 0; i < block_nums; i++) {
		list<RLENode> rleNodeList = rleEncoder_v.encode(split_v_z + (i << 6));
		list<BITNode> bitNodeList = bitEncoder.encode(rleNodeList);
		BitNodeList_v.push_back(bitNodeList);
	}



	free(split_y_z);
	free(split_u_z);
	free(split_v_z);
	
	//8.哈夫曼编码
	JPEGEncoder jpegEncoder;

	list<list<BITNode> >::iterator it;
	for (int i = 0; i < block_nums; i++) {
		list<BITNode> y = BitNodeList_y.front();
		list<BITNode> u = BitNodeList_u.front();
		list<BITNode> v = BitNodeList_v.front();

		list<BITNode>::iterator ite;
		

		BitNodeList_y.pop_front();
		BitNodeList_u.pop_front();
		BitNodeList_v.pop_front();

		list<HuffmanNode> huffmanNodeList_y = huffmanTable.encodeY(y);
		list<HuffmanNode> huffmanNodeList_u = huffmanTable.encodeC(u);
		list<HuffmanNode> huffmanNodeList_v = huffmanTable.encodeC(v);

		jpegEncoder.addImage(huffmanNodeList_y);
		jpegEncoder.addImage(huffmanNodeList_u);
		jpegEncoder.addImage(huffmanNodeList_v);
		
	}
	jpegEncoder.mergeMCU();
	
	//9.其他图片信息	
	jpegEncoder.addSOI();
	jpegEncoder.addAPP0();
	jpegEncoder.addSOF0(h, w);
	jpegEncoder.addHuffmanTree(&huffmanTable);
	jpegEncoder.addSOS();
	jpegEncoder.addYDQT(qTable);
	jpegEncoder.addCDQT(qTableC);
	jpegEncoder.addEOI();
	list<Bits> finalJPEG = jpegEncoder.exportBits();
	printf("bb\n");

	
	//10.存入文件
	//BitsWriter writer("D://out.jpeg");
	BitsWriter writer(out_path.data());
	writer.write(finalJPEG);
	
	return 0;
}

