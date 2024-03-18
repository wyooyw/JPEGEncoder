#include <map>
#include "Bits.h"
#include "HuffmanTreeNode.h"
#include <queue>
#include <vector>
#include <list>
#pragma once
using namespace std;
class HuffmanTree {
private:
	map<int, Bits> encodeTable;
	HuffmanTreeNode* root;
	void traverse(HuffmanTreeNode* cur);
	void traverse2(HuffmanTreeNode* cur, int step);
	queue<int> values;			//按照从左到右，从上到下的顺序的value
	//计算中需要用到的变量
	Bits road;
	map<int, int> node_floor;
	int floor_num[20];
	int max_floor;
public:
	HuffmanTree(map<int, int> count);
	Bits encode(int num);
	list<Bits> exportBits(int type, int num);
};