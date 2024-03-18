#include "BITEncoder.h"
list<BITNode> BITEncoder::encode(list<RLENode> RLEList) {
	list<BITNode> BITNodeList;

	list<RLENode>::iterator iter;
	for (iter = RLEList.begin(); iter != RLEList.end(); iter++) {
		if (iter->isEOB()) {
			BITNode bitNode;
			bitNode.setEOB(true);
			bitNode.setLength(0);

			Bits bits(0,0);
			bitNode.setCode(bits);
			bitNode.setDC(BITNodeList.size() == 0);
			BITNodeList.push_back(bitNode);
			continue;
		}
		int length = iter->getLength();
		int code = iter->getCode();
		Bits bits = encodeTable.getBits(code);
		length = (length << 4) + bits.getLength();
		BITNode bitNode(length, bits);
		//如果是本块第一个，则是直流
		if (BITNodeList.size() == 0) {
			bitNode.setDC(true);
			//printf("%d\n",bitNode.getLength());
		}
		BITNodeList.push_back(bitNode);
	}
	return BITNodeList;
}