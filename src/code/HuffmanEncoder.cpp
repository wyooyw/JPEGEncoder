#include "HuffmanEncoder.h";
void HuffmanEncoder::build(list<BITNode> bigNodeList) {
	//1.分别统计直流和交流
	map<int, int>::iterator mapiter;

	list<BITNode>::iterator iter;
	int a = 0, b = 0, c = 0, d = 0;
	for (iter = bigNodeList.begin(); iter != bigNodeList.end(); iter++) {
		if (iter->isDC()) {
			//加在直流里
			int key = iter->getLength();
			mapiter = DCcount.find(key);
			if (mapiter == DCcount.end()) {
				DCcount.insert(make_pair(key, 1));
			}
			else {
				mapiter->second += 1;
			}
		}
		else {
			//加在交流里
			int key = iter->getLength();
			mapiter = ACcount.find(key);
			if (mapiter == ACcount.end()) {
				ACcount.insert(make_pair(key, 1));
			}
			else {
				mapiter->second += 1;
			}
		}

	}
}

void HuffmanEncoder::buildTree() {
	//2.构建哈夫曼树
	DCTree = new HuffmanTree(DCcount);
	ACTree = new HuffmanTree(ACcount);

}

list<HuffmanNode> HuffmanEncoder::encode(list<BITNode> bitNodeList) {
	
	//3.编码
	list<HuffmanNode> huffmanNodeList;
	list<BITNode>::iterator iter;
	for (iter = bitNodeList.begin(); iter != bitNodeList.end(); iter++) {
		HuffmanNode huffmanNode;
		huffmanNode.setCode(iter->getCode());

		if (iter->isDC()) {
			huffmanNode.setLength(DCTree->encode(iter->getLength()));
		}
		else {
			huffmanNode.setLength(ACTree->encode(iter->getLength()));
		}
		huffmanNodeList.push_back(huffmanNode);
	}
	return huffmanNodeList;
}


HuffmanTree* HuffmanEncoder::getDCTree() {
	return DCTree;
}
HuffmanTree* HuffmanEncoder::getACTree() {
	return ACTree;

}
void HuffmanEncoder::print() {

	printf("DCcount:%d;ACcount:%d\n",DCcount.size(),ACcount.size());
}