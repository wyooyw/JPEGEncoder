#include "byte.h"
#include "Bits.h"

Bits::Bits() {

}
Bits::Bits(int l, bits_unit b) {
	length = l;
	bits = b;
}

int Bits::getLength() {
	return length;
}
void Bits::setLength(int l) {
	length = l;
}
bits_unit Bits::getBits() {
	if (length == 32) {
		return bits;
	}
	return bits & ((1<<length)-1);
}
void Bits::setBits(bits_unit b) {
	bits = b;
}
void Bits::print() {
	printf("(%d,", length);
	for (int i = length-1; i >= 0; i--) {
		printf("%d",(bits>>i)&1);
	}
	printf(")");
}

void Bits::println() {
	print();
	printf("\n");
}

Bits Bits::copy() {
	Bits b(length,bits);
	return b;
}

void Bits::push_back(int i) {
	length += 1;
	bits = (bits << 1) + i;
}

void Bits::pop_back() {
	length -= 1;
	bits = bits >> 1;
}