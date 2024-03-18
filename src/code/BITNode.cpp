#include "BITNode.h"
BITNode::BITNode() {

}
BITNode::BITNode(int l, Bits c) {
	length = l;
	code = c;
}
int BITNode::getLength() {
	return length;
}
Bits BITNode::getCode() {
	return code;
}
void BITNode::setLength(int l) {
	length = l;
}
void BITNode::setCode(Bits c) {
	code = c;
}

void BITNode::setEOB(bool eob) {
	EOB = eob;
}
bool BITNode::isEOB() {
	return EOB;
}
void BITNode::setDC(bool dc) {
	DC = dc;
}
bool BITNode::isDC() {
	return DC;
}
void BITNode::print() {
	printf("BITNode:length=%d,code=", length);
	code.print();
	printf(",isDC=%d,isEOB=%d\n",DC,EOB);
}