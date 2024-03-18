#pragma once
#include "Bits.h"
class HuffmanNode {
private:
	Bits length;
	Bits code;
public:
	HuffmanNode();
	HuffmanNode(Bits l, Bits c);
	Bits getLength();
	Bits getCode();
	void setLength(Bits l);
	void setCode(Bits c);

	void print();
};