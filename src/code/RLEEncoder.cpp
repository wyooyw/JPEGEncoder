#include "RLEEncoder.h"
RLEEncoder::RLEEncoder() {
	lastCode = 0;
}

list<RLENode> RLEEncoder::encode(int* src) {
	list<RLENode> RLENodeList;
	int length = 0;
	int accZero = 0;

	if (*src != 0) {
		for (int i = 0; i < 64; i++) {
			if ((*(src + i)) == 0 && accZero < 15) {
				accZero++;
			}
			else {
				RLENode node(accZero, *(src + i));
				//如果是本块的第一个，则是直流
				if (RLENodeList.size() == 0) {
					node.setDC(true);
					//printf("lastCode:%d\n",lastCode);
					node.setCode(*(src + i) - lastCode);
					lastCode = *(src + i);
				}
				RLENodeList.push_back(node);
				accZero = 0;
			}
		}
		if (accZero > 0) {
			RLENode node;
			node.setEOB(true);
			RLENodeList.push_back(node);
		}
	}
	else {
		RLENode nodeDC(0,0);
		nodeDC.setEOB(true);
		RLENode nodeAC(0, 0);
		nodeDC.setEOB(true);
		RLENodeList.push_back(nodeDC);
		RLENodeList.push_back(nodeAC);
	}
	
	
	return RLENodeList;
}