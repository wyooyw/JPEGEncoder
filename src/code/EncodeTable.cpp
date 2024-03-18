#include "EncodeTable.h";
EncodeTable::EncodeTable() {
	ranges[0] = make_pair(0, 0);
	ranges[1] = make_pair(1,1);
	ranges[2] = make_pair(2, 3);
	ranges[3] = make_pair(4, 7);
	ranges[4] = make_pair(8, 15);
	ranges[5] = make_pair(16, 31);
	ranges[6] = make_pair(32, 63);
	ranges[7] = make_pair(64, 127);
	ranges[8] = make_pair(128, 255);
	ranges[9] = make_pair(256, 511);
	ranges[10] = make_pair(512, 1023);
	ranges[11] = make_pair(1024, 2047);
}
Bits EncodeTable::getBits(int value) {
	int value_abs = value >= 0 ? value : -value;
	int size;
	bits_unit bits;
	int i;
	for (i = 0; i < 12; i++) {
		if (value_abs >= ranges[i].first && value_abs <= ranges[i].second) {
			break;
		}
	}
	size = i;
	if (size >= 12) {
		printf("error:value_abs=%d!\n", value_abs);
		Bits b(1,1);
		return b;
	}
	if (value <= 0) {
		bits = value + ranges[size].second;
	}
	else {
		bits = value - ranges[size].first + (ranges[size].second - ranges[size].first) + 1;
	}
	Bits b(size, bits);
	return b;
}