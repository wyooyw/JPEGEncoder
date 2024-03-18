#include "JPEGEncoder.h"

JPEGEncoder::JPEGEncoder() {
	
}


void JPEGEncoder::addSOI() {
	//FF D8
	Bits b1(8, 255);
	Bits b2(8, 216);
	SOI.push_back(b1);
	SOI.push_back(b2);
}

void JPEGEncoder::addAPP0() {
	//FF E0
	Bits b1(8, 255);
	Bits b2(8, 224);
	//段长度
	Bits segLen(16, 16);
	//交换格式 “JFIF”的ASCII码
	Bits jfif1(32, 1246120262);
	Bits jfif2(8, 0);
	//主版本号、次版本号
	Bits main_version(8, 1);
	Bits secondary_version(8, 1);
	//密度单位
	Bits density_unit(8, 1);
	//X,Y像素密度
	Bits density_x(16, 96);
	Bits density_y(16, 96);
	//缩略图X,Y像素
	Bits thumbnailX(8, 0);
	Bits thumbnailY(8, 0);

	APP0.push_back(b1);
	APP0.push_back(b2);
	APP0.push_back(segLen);
	APP0.push_back(jfif1);
	APP0.push_back(jfif2);
	APP0.push_back(main_version);
	APP0.push_back(secondary_version);
	APP0.push_back(density_unit);
	APP0.push_back(density_x);
	APP0.push_back(density_y);
	APP0.push_back(thumbnailX);
	APP0.push_back(thumbnailY);
}

void JPEGEncoder::addDQT(int QTid, int* qtable) {
	//FF E0
	Bits b1(8, 255);
	Bits b2(8, 219);
	//段长度
	Bits segLen(16, 67);
	//QT信息-前
	Bits info1(4, QTid);
	//QT信息-后
	Bits info2(4, 0);

	DQT.push_back(b1);
	DQT.push_back(b2);
	DQT.push_back(segLen);
	DQT.push_back(info2);
	DQT.push_back(info1);

	//QT
	for (int i = 0; i < 64; i++) {
		Bits DQ_item(8,*(qtable + i));
		DQT.push_back(DQ_item);
	}
}

void JPEGEncoder::addSOF0(int w,int h) {
	//FF C0
	Bits b1(8, 255);
	Bits b2(8, 192);
	//段长度
	Bits segLen(16, 17);
	//样本精度
	Bits accuarcy(8, 8);
	//图片高度
	Bits height(16, h);
	//图片宽度
	Bits width(16, w);
	//组件数量
	Bits componentNum(8,3);
	//组件1
	Bits componentID1(8,1);
	Bits componentSample1_1(4, 1);
	Bits componentSample1_2(4, 1);
	Bits componentQT1(8, 0);

	//组件2
	Bits componentID2(8, 2);
	Bits componentSample2_1(4, 1);
	Bits componentSample2_2(4, 1);
	Bits componentQT2(8, 1);

	//组件3
	Bits componentID3(8, 3);
	Bits componentSample3_1(4, 1);
	Bits componentSample3_2(4, 1);
	Bits componentQT3(8, 1);

	SOF0.push_back(b1);
	SOF0.push_back(b2);
	SOF0.push_back(segLen);
	SOF0.push_back(accuarcy);
	SOF0.push_back(width);
	SOF0.push_back(height);
	SOF0.push_back(componentNum);

	SOF0.push_back(componentID1);
	SOF0.push_back(componentSample1_1);
	SOF0.push_back(componentSample1_2);
	SOF0.push_back(componentQT1);

	SOF0.push_back(componentID2);
	SOF0.push_back(componentSample2_1);
	SOF0.push_back(componentSample2_2);
	SOF0.push_back(componentQT2);

	SOF0.push_back(componentID3);
	SOF0.push_back(componentSample3_1);
	SOF0.push_back(componentSample3_2);
	SOF0.push_back(componentQT3);
}

//Y量化表
void JPEGEncoder::addYDQT(int* qtable) {
	addDQT(0, qtable);
}

//C量化表
void JPEGEncoder::addCDQT(int* qtable) {
	addDQT(1, qtable);
}

//霍夫曼表
void JPEGEncoder::addHuffmanTree(HuffmanTable *huffmanTable) {
	DHT = huffmanTable->exportAll();

}

//压缩后的图片
void JPEGEncoder::addSOS() {
	//FF DA
	Bits b1(8, 255);
	Bits b2(8, 218);
	//段长度
	Bits segLen(16, 12);
	//组件数量
	Bits componentNum(8,3);

	//组件id
	Bits componentID1(8,1);
	//霍夫曼表号
	Bits huffmanID1(8, 0);

	//组件id
	Bits componentID2(8, 2);
	//霍夫曼表号
	Bits huffmanID2(8, 17);

	//组件id
	Bits componentID3(8, 3);
	//霍夫曼表号
	Bits huffmanID3(8, 17);

	//无用的3个字节
	Bits nouse(24, 16128);

	SOS.push_back(b1);
	SOS.push_back(b2);
	SOS.push_back(segLen);
	SOS.push_back(componentNum);
	SOS.push_back(componentID1);
	SOS.push_back(huffmanID1);
	SOS.push_back(componentID2);
	SOS.push_back(huffmanID2);
	SOS.push_back(componentID3);
	SOS.push_back(huffmanID3);
	SOS.push_back(nouse);
}

//压缩后的图片
void JPEGEncoder::addImage(list<HuffmanNode> huffmanNodeList) {
	list<HuffmanNode>::iterator iter;
	list<Bits> tmpImage;
	for (iter = huffmanNodeList.begin(); iter != huffmanNodeList.end(); iter++) {
		tmpImage.push_back(iter->getLength());
		tmpImage.push_back(iter->getCode());
	}
	//tmpImage = merger.merge(tmpImage, 0);
	image_MCU.splice(image_MCU.end(), tmpImage);
	/*list<Bits>::iterator it;
	for (it = image.begin(); it != image.end(); it++) {
		it->println();
	}
	printf("\n");*/
}

void JPEGEncoder::mergeMCU() {
	image_MCU = merger.merge(image_MCU, 0);
	image_MCU = merger.replaceFF(image_MCU);
	image.splice(image.end(), image_MCU);
}

void JPEGEncoder::addEOI() {
	//FF D9
	Bits b1(8, 255);
	Bits b2(8, 217);
	EOI.push_back(b1);
	EOI.push_back(b2);
}


//导出
list<Bits> JPEGEncoder::exportBits() {
	
	list<Bits> all = SOI;
	all.splice(all.end(), APP0);
	all.splice(all.end(), DQT);
	all.splice(all.end(), SOF0);
	all.splice(all.end(), DHT);
	all.splice(all.end(), SOS);
	all.splice(all.end(), image);
	
	list<Bits> mergeList = merger.merge(all,0);
	Bits b1(8, 255);
	Bits b2(8, 217);
	mergeList.push_back(b1);
	mergeList.push_back(b2);
	Bits b3(8, 0);
	Bits b4(8, 0);
	mergeList.push_back(b3);
	mergeList.push_back(b4);
	mergeList = merger.merge(mergeList, 0);

	return mergeList;
}