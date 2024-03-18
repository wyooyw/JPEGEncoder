#pragma once
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include "HuffmanEncoder.h"
#include "BitsMerger.h"
#include "HuffmanTable.h"
class JPEGEncoder {
private:
	list<Bits> SOI;
	list<Bits> APP0;

	list<Bits> DQT;
	list<Bits> SOF0;

	list<Bits> DHT;
	list<Bits> SOS;
	list<Bits> image;
	list<Bits> image_MCU;
	list<Bits> EOI;

	BitsMerger merger;
	
public:
	JPEGEncoder();

	void addSOI();

	void addAPP0();

	void addSOF0(int w, int h);

	//霍夫曼表
	void addHuffmanTree(HuffmanTable* huffmanTable);

	//压缩后的图片
	void addSOS();

	void addImage(list<HuffmanNode> huffmanNodeList);

	void mergeMCU();

	//量化表
	void addYDQT(int* qtable);

	void addCDQT(int *qtable);

	void addDQT(int QTid,int* qtable);

	void addEOI();

	

	//导出
	list<Bits> exportBits();
};