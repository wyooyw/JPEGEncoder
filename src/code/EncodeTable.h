#include "byte.h"
#include "Bits.h"
#include<list>
#pragma once
class EncodeTable {
private:
	pair<int, int> ranges[12];
public:
	EncodeTable();
	Bits getBits(int value);
};