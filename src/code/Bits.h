#pragma once
#include "byte.h"
#include <stdio.h>
using namespace std;
class Bits {
private:
	int length = 0;
	bits_unit bits = 0;
public:
	Bits();
	Bits(int l, bits_unit b);
	int getLength();
	void setLength(int l);
	bits_unit getBits();
	void setBits(bits_unit b);
	void print();
	void println();
	Bits copy();
	void push_back(int i);
	void pop_back();
};