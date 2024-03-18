#include "HuffmanNode.h"

HuffmanNode::HuffmanNode() {

}
HuffmanNode::HuffmanNode(Bits l, Bits c) {
	length = l;
	code = c;
}
Bits HuffmanNode::getLength() {
	return length;
}
Bits HuffmanNode::getCode() {
	return code;
}
void HuffmanNode::setLength(Bits l) {
	length = l;
}
void HuffmanNode::setCode(Bits c) {
	code = c;
}

void HuffmanNode::print() {
	printf("HuffmanNode:");
	length.print();
	code.print();
	printf("\n");
}