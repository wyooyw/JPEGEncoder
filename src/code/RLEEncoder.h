#include <list>
#include "RLENode.h"
using namespace std;
#pragma once
class RLEEncoder {
private:
	int lastCode = 0;
public:
	RLEEncoder();
	list<RLENode> encode(int *src);
};