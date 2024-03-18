#include "HuffmanNode.h"
#include "BITNode.h"
#include <list>
#include <map>
#include "HuffmanTree.h"
#pragma once
using namespace std;
class HuffmanEncoder {
private:
	HuffmanTree *DCTree;
	HuffmanTree *ACTree;
	map<int, int> DCcount;
	map<int, int> ACcount;
public:
	void build(list<BITNode> bigNodeList);
	list<HuffmanNode> encode(list<BITNode> bigNodeList);
	HuffmanTree* getDCTree();
	HuffmanTree* getACTree();
	void buildTree();
	void print();
};