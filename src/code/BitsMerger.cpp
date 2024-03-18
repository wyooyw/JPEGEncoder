#include "BitsMerger.h"


list<Bits> BitsMerger::merge(list<Bits> bitsList,int fill) {
	list<Bits> result;
	list<Bits>::iterator iter;
	bits_unit wholeByte = 0;
	int bits_unit_size = sizeof(bits_unit) << 3;
	int ptr = bits_unit_size - 1;
	for (iter = bitsList.begin(); iter != bitsList.end(); iter++) {
		int length = iter->getLength();
		bits_unit bits = iter->getBits();
		
		if (length >= ptr + 1) {
			int front_bits_len = ptr+1;
			int end_bits_len = length - front_bits_len;
			bits_unit frontbits = bits >> end_bits_len;
			bits_unit behindbits = bits & ((1 << end_bits_len) - 1);
			//iter->print();
			//printf("%d,%d,%d,%d\n", front_bits_len, end_bits_len, wholeByte, frontbits);
			wholeByte = wholeByte + frontbits;
			Bits b(bits_unit_size, wholeByte);
			result.push_back(b);
			
			wholeByte = behindbits << (bits_unit_size - end_bits_len);
			ptr = (bits_unit_size - 1) - end_bits_len;

		}
		else {
			wholeByte += bits << (ptr + 1 - length);
			ptr -= length;
		}
	}
	if (ptr < (bits_unit_size - 1)) {
		if (fill == 0) {
			int low = (ptr + 1) / 8 * 8;
			Bits b(bits_unit_size-low, wholeByte>>low);
			result.push_back(b);
		}
		
	}
	return result;
}

list<Bits> BitsMerger::merge(list<HuffmanNode> haffmanNodeList,int fill) {
	list<Bits> bitsList;
	list<HuffmanNode>::iterator iter;
	for (iter = haffmanNodeList.begin(); iter != haffmanNodeList.end(); iter++) {
		bitsList.push_back(iter->getLength());
		bitsList.push_back(iter->getCode());
	}
	return merge(bitsList,fill);
}


//把FF换为FF00，bitsList应为已经merge过的
list<Bits> BitsMerger::replaceFF(list<Bits> bitsList) {
	list<Bits>::iterator iter;
	printf("begin replace FF\n");
	for (iter = bitsList.begin(); iter != bitsList.end(); iter++) {
		int length = iter->getLength();
		bits_unit bits = iter->getBits();
		int size = min((int)sizeof(bits_unit)*8,length);
		//iter->println ();
		int flag = 0;
		for (int i = size - 8; i >= 0; i -= 8) {
			//printf("--%d--", ((bits >> i) & 255));
			if (((bits >> i)&255) == 255) {
				//printf("aaa");
				iter->setLength(size-i);
				iter->setBits(bits>>i);
				Bits zeros(8,0);
				Bits remain(i, bits);

				iter++;
				bitsList.insert(iter, zeros);
				bitsList.insert(iter, remain);
				iter--;
				iter--;


				flag = 1;
				break;
			}
		}
	}
	printf("end replace FF\n");

	return bitsList;
}