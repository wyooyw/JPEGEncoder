#pragma once
#include <stdio.h>
class RLENode {
private:
	int length;
	int code;
	bool EOB = false;
	bool DC = false;
public:
	RLENode();
	RLENode(int l, int c);
	int getLength();
	int getCode();
	void setLength(int l);
	void setCode(int c);
	void setEOB(bool eob);
	bool isEOB();
	void setDC(bool dc);
	bool isDC();
	void print();
};