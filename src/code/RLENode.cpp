#include "RLENode.h"
RLENode::RLENode() {

}
RLENode::RLENode(int l, int c) {
	length = l;
	code = c;
}
int RLENode::getLength() {
	return length;
}
int RLENode::getCode() {
	return code;
}
void RLENode::setLength(int l) {
	length = l;
}
void RLENode::setCode(int c) {
	code = c;
}

void RLENode::setEOB(bool eob) {
	EOB = eob;
}
bool RLENode::isEOB() {
	return EOB;
}
void RLENode::setDC(bool dc) {
	DC = dc;
}
bool RLENode::isDC() {
	return DC;
}

void RLENode::print() {
	printf("RLENode:length=%d,code=%d,isDC=%d,isEOB=%d\n", length,code,DC,EOB);
}