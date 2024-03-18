#pragma once
#include "byte.h"
#include "Bits.h"
#include "HuffmanNode.h"
#include<list>
#include <algorithm>
using namespace std;
class BitsMerger {
public:
	list<Bits> merge(list<Bits> bitsList,int fill);
	list<Bits> merge(list<HuffmanNode> haffmanNodeList,int fill);
	list<Bits> replaceFF(list<Bits> bitsList);
};