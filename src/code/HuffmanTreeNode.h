#pragma once
class HuffmanTreeNode {
private:
	int value;
	int count;
	bool leaf;
	HuffmanTreeNode* left;
	HuffmanTreeNode* right;
public:
	HuffmanTreeNode();
	void setValue(int v);
	int getValue();
	void setCount(int c);
	int getCount();
	void setLeaf(bool l);
	bool isLeaf();
	void setLeft(HuffmanTreeNode* l);
	HuffmanTreeNode* getLeft();
	void setRight(HuffmanTreeNode* r);
	HuffmanTreeNode* getRight();
	
};
struct HuffmanTreeNodeCmp //ÖØÐ´·Âº¯Êý
{
	bool operator() (HuffmanTreeNode *a, HuffmanTreeNode *b)
	{
		return a->getCount() > b->getCount(); //´ó¶¥¶Ñ
	}
};