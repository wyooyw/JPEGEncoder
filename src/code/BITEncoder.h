#include "EncodeTable.h"
#include "RLENode.h"
#include "BITNode.h"
#pragma once
class BITEncoder {
private:
	EncodeTable encodeTable;
public:
	list<BITNode> encode(list<RLENode> RLEList);
};