#include "HuffmanTreeNode.h"
HuffmanTreeNode::HuffmanTreeNode() {
	value = 0;
	count = 0;
	leaf = false;
	left = 0;
	right = 0;
}
void HuffmanTreeNode::setValue(int v) {
	value = v;
}
int HuffmanTreeNode::getValue() {
	return value;
}
void HuffmanTreeNode::setCount(int c) {
	count = c;
}
int HuffmanTreeNode::getCount() {
	return count;
}
void HuffmanTreeNode::setLeaf(bool l) {
	leaf = l;
}
bool HuffmanTreeNode::isLeaf() {
	return leaf;
}
void HuffmanTreeNode::setLeft(HuffmanTreeNode* l) {
	left = l;
}
HuffmanTreeNode* HuffmanTreeNode::getLeft() {
	return left;
}
void HuffmanTreeNode::setRight(HuffmanTreeNode* r) {
	right = r;
}
HuffmanTreeNode* HuffmanTreeNode::getRight() {
	return right;
}
