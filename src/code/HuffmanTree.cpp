#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(map<int, int> count) {
	//1.构建哈夫曼树
	priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>, HuffmanTreeNodeCmp> q;
	priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, HuffmanTreeNodeCmp> q2;
	map<int, int>::iterator iter;
	int i = 0;
	//至少两个叶节点
	if (count.size() == 1) {
		if (count.find(1) == count.end()) {
			count.insert(make_pair(1, 0));
		}
		else {
			count.insert(make_pair(2, 0));
		}
		
	}
	for (iter = count.begin(); iter != count.end(); iter++) {
		HuffmanTreeNode *node = new HuffmanTreeNode();
		node->setValue(iter->first);
		node->setCount(iter->second);
		node->setLeaf(true);
		q.push(node);
		q2.push(node);
		floor_num[i++] = 0;
	}
	while (q.size() > 1) {
		HuffmanTreeNode* node1 = q.top();
		q.pop();
		HuffmanTreeNode* node2 = q.top();
		q.pop();
		//printf("%d %d\n", node1->getCount(),node2->getCount());
		HuffmanTreeNode* node = new HuffmanTreeNode();
		node->setCount(node1->getCount() + node2->getCount());
		node->setLeft(node1);
		node->setRight(node2);
		node->setLeaf(false);
		q.push(node);
	}
	root = q.top();

	//2.计算每个节点在第几层,每层有几个节点，最深有几层，并顺便释放内存
	max_floor = 0;
	traverse2(root, 0);

	//3.构建规范哈夫曼树
	i = max_floor;
	deque<HuffmanTreeNode*> q3;
	//printf("size=%d\n", q2.size());
	while (i>0) {
		//printf("%d\n", floor_num[i]);
		for (int j = floor_num[i]; j > 0; j--) {
			q3.push_front(q2.top());
			q2.pop();
		}
		//printf("k=%d\n", q3.size());
		int k = q3.size();
		while (k>0) {
			HuffmanTreeNode* node = new HuffmanTreeNode();
			node->setLeft(q3.front());
			q3.pop_front();
			node->setRight(q3.front());
			q3.pop_front();
			q3.push_back(node);
			k -= 2;
		}
		i--;
	}
	root = q3.front();

	//4.填入节点
	traverse(root);
	
}

void HuffmanTree::traverse2(HuffmanTreeNode* cur,int step) {
	if (cur->isLeaf()) {
		//printf("%d ", cur->getCount());
		//node_floor.insert(make_pair(cur->getValue(),step));
		floor_num[step]++;
		if (step > max_floor) {
			max_floor = step;
		}
		return;
	}
	traverse2(cur->getLeft(),step+1);
	traverse2(cur->getRight(), step + 1);
	free(cur);
}

void HuffmanTree::traverse(HuffmanTreeNode *cur) {
	//("%d ", cur->getCount());
	if (cur->isLeaf()) {
		//printf("%d ", cur->getCount());
		//road.print();
		encodeTable.insert(make_pair(cur->getValue(),road.copy()));
		values.push(cur->getValue());
		return;
	}
	road.push_back(0);
	traverse(cur->getLeft());
	road.pop_back();

	road.push_back(1);
	traverse(cur->getRight());
	road.pop_back();
}

Bits HuffmanTree::encode(int num) {
	map<int, Bits>::iterator iter = encodeTable.find(num);
	if (iter == encodeTable.end()) {
		printf("HuffmanTree encode error!\n");
		Bits bits;
		return bits;
	}
	return iter->second;
}

//type=0:直流;type=1:交流;num:表的编号
list<Bits> HuffmanTree::exportBits(int type,int num) {
	list<Bits> bitsList;

	Bits b1(8,255 );
	Bits b2(8,196);
	Bits segSize(16, 19 + values.size());
	bitsList.push_back(b1);
	bitsList.push_back(b2);
	bitsList.push_back(segSize);

	Bits bits_zeros(3, 0);
	Bits bits_type(1, type);
	Bits bits_num(4,num);
	
	bitsList.push_back(bits_zeros);
	bitsList.push_back(bits_type);
	bitsList.push_back(bits_num);
	

	for (int i = 1; i <= 16; i++) {
		Bits num_of_leaf(8, floor_num[i]);
		bitsList.push_back(num_of_leaf);
	}

	while (values.size() > 0) {
		Bits value_of_leaf(8, values.front());
		values.pop();
		bitsList.push_back(value_of_leaf);
	}
	return bitsList;
}