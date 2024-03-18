#include "Bits.h"
#pragma once
class BITNode {
private:
	int length;
	Bits code;
	bool EOB = false;
	bool DC = false;
public:
	BITNode();
	BITNode(int l, Bits c);
	int getLength();
	Bits getCode();
	void setLength(int l);
	void setCode(Bits c);
	void setEOB(bool eob);
	bool isEOB();

	void setDC(bool dc);
	bool isDC();

	void print();
};