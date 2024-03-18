#include "HuffmanTable.h"
HuffmanTable::HuffmanTable() {
	for (int i = 0; i <= 16; i++) {
		Y_AC_floor_num[i] = 0;
		Y_DC_floor_num[i] = 0;
		C_AC_floor_num[i] = 0;
		C_DC_floor_num[i] = 0;
	}


	//亮度 直流
	insertY_DC(0, 0, 2, 0);
	insertY_DC(0, 1, 3, 2);
	insertY_DC(0, 2, 3, 3);
	insertY_DC(0, 3, 3, 4);
	insertY_DC(0, 4, 3, 5);
	insertY_DC(0, 5, 3, 6);
	insertY_DC(0, 6, 4, 14);
	insertY_DC(0, 7, 5, 30);
	insertY_DC(0, 8, 6, 62);
	insertY_DC(0, 9, 7, 126);
	insertY_DC(0, 10, 8, 254);
	insertY_DC(0,11,9,510);

	//亮度 交流
	insertY_AC(0, 0, 4, 10);
	insertY_AC(0, 1, 2, 0);
	insertY_AC(0, 2, 2, 1);
	insertY_AC(0, 3, 3, 4);
	insertY_AC(0, 4, 4, 11);
	insertY_AC(0, 5, 5, 26);
	insertY_AC(0, 6, 7, 120);
	insertY_AC(0, 7, 8, 248);
	insertY_AC(0, 8, 10, 1014);
	insertY_AC(0, 9, 16, 65410);
	insertY_AC(0, 10, 16, 65411);
	insertY_AC(1, 1, 4, 12);
	insertY_AC(1, 2, 5, 27);
	insertY_AC(1, 3, 7, 121);
	insertY_AC(1, 4, 9, 502);
	insertY_AC(1, 5, 11, 2038);
	insertY_AC(1, 6, 16, 65412);
	insertY_AC(1, 7, 16, 65413);
	insertY_AC(1, 8, 16, 65414);
	insertY_AC(1, 9, 16, 65415);
	insertY_AC(1, 10, 16, 65416);
	insertY_AC(2, 1, 5, 28);
	insertY_AC(2, 2, 8, 249);
	insertY_AC(2, 3, 10, 1015);
	insertY_AC(2, 4, 12, 4084);
	insertY_AC(2, 5, 16, 65417);
	insertY_AC(2, 6, 16, 65418);
	insertY_AC(2, 7, 16, 65419);
	insertY_AC(2, 8, 16, 65420);
	insertY_AC(2, 9, 16, 65421);
	insertY_AC(2, 10, 16, 65422);
	insertY_AC(3, 1, 6, 58);
	insertY_AC(3, 2, 9, 503);
	insertY_AC(3, 3, 12, 4085);
	insertY_AC(3, 4, 16, 65423);
	insertY_AC(3, 5, 16, 65424);
	insertY_AC(3, 6, 16, 65425);
	insertY_AC(3, 7, 16, 65426);
	insertY_AC(3, 8, 16, 65427);
	insertY_AC(3, 9, 16, 65428);
	insertY_AC(3, 10, 16, 65429);
	insertY_AC(4, 1, 6, 59);
	insertY_AC(4, 2, 10, 1016);
	insertY_AC(4, 3, 16, 65430);
	insertY_AC(4, 4, 16, 65431);
	insertY_AC(4, 5, 16, 65432);
	insertY_AC(4, 6, 16, 65433);
	insertY_AC(4, 7, 16, 65434);
	insertY_AC(4, 8, 16, 65435);
	insertY_AC(4, 9, 16, 65436);
	insertY_AC(4, 10, 16, 65437);
	insertY_AC(5, 1, 7, 122);
	insertY_AC(5, 2, 11, 2039);
	insertY_AC(5, 3, 16, 65438);
	insertY_AC(5, 4, 16, 65439);
	insertY_AC(5, 5, 16, 65440);
	insertY_AC(5, 6, 16, 65441);
	insertY_AC(5, 7, 16, 65442);
	insertY_AC(5, 8, 16, 65443);
	insertY_AC(5, 9, 16, 65444);
	insertY_AC(5, 10, 16, 65445);
	insertY_AC(6, 1, 7, 123);
	insertY_AC(6, 2, 12, 4086);
	insertY_AC(6, 3, 16, 65446);
	insertY_AC(6, 4, 16, 65447);
	insertY_AC(6, 5, 16, 65448);
	insertY_AC(6, 6, 16, 65449);
	insertY_AC(6, 7, 16, 65450);
	insertY_AC(6, 8, 16, 65451);
	insertY_AC(6, 9, 16, 65452);
	insertY_AC(6, 10, 16, 65453);
	insertY_AC(7, 1, 8, 250);
	insertY_AC(7, 2, 12, 4087);
	insertY_AC(7, 3, 16, 65454);
	insertY_AC(7, 4, 16, 65455);
	insertY_AC(7, 5, 16, 65456);
	insertY_AC(7, 6, 16, 65457);
	insertY_AC(7, 7, 16, 65458);
	insertY_AC(7, 8, 16, 65459);
	insertY_AC(7, 9, 16, 65460);
	insertY_AC(7, 10, 16, 65461);
	insertY_AC(8, 1, 9, 504);
	insertY_AC(8, 2, 15, 32704);
	insertY_AC(8, 3, 16, 65462);
	insertY_AC(8, 4, 16, 65463);
	insertY_AC(8, 5, 16, 65464);
	insertY_AC(8, 6, 16, 65465);
	insertY_AC(8, 7, 16, 65466);
	insertY_AC(8, 8, 16, 65467);
	insertY_AC(8, 9, 16, 65468);
	insertY_AC(8, 10, 16, 65469);
	insertY_AC(9, 1, 9, 505);
	insertY_AC(9, 2, 16, 65470);
	insertY_AC(9, 3, 16, 65471);
	insertY_AC(9, 4, 16, 65472);
	insertY_AC(9, 5, 16, 65473);
	insertY_AC(9, 6, 16, 65474);
	insertY_AC(9, 7, 16, 65475);
	insertY_AC(9, 8, 16, 65476);
	insertY_AC(9, 9, 16, 65477);
	insertY_AC(9, 10, 16, 65478);
	insertY_AC(10, 1, 9, 506);
	insertY_AC(10, 2, 16, 65479);
	insertY_AC(10, 3, 16, 65480);
	insertY_AC(10, 4, 16, 65481);
	insertY_AC(10, 5, 16, 65482);
	insertY_AC(10, 6, 16, 65483);
	insertY_AC(10, 7, 16, 65484);
	insertY_AC(10, 8, 16, 65485);
	insertY_AC(10, 9, 16, 65486);
	insertY_AC(10, 10, 16, 65487);
	insertY_AC(11, 1, 10, 1017);
	insertY_AC(11, 2, 16, 65488);
	insertY_AC(11, 3, 16, 65489);
	insertY_AC(11, 4, 16, 65490);
	insertY_AC(11, 5, 16, 65491);
	insertY_AC(11, 6, 16, 65492);
	insertY_AC(11, 7, 16, 65493);
	insertY_AC(11, 8, 16, 65494);
	insertY_AC(11, 9, 16, 65495);
	insertY_AC(11, 10, 16, 65496);
	insertY_AC(12, 1, 10, 1018);
	insertY_AC(12, 2, 16, 65497);
	insertY_AC(12, 3, 16, 65498);
	insertY_AC(12, 4, 16, 65499);
	insertY_AC(12, 5, 16, 65500);
	insertY_AC(12, 6, 16, 65501);
	insertY_AC(12, 7, 16, 65502);
	insertY_AC(12, 8, 16, 65503);
	insertY_AC(12, 9, 16, 65504);
	insertY_AC(12, 10, 16, 65505);
	insertY_AC(13, 1, 11, 2040);
	insertY_AC(13, 2, 16, 65506);
	insertY_AC(13, 3, 16, 65507);
	insertY_AC(13, 4, 16, 65508);
	insertY_AC(13, 5, 16, 65509);
	insertY_AC(13, 6, 16, 65510);
	insertY_AC(13, 7, 16, 65511);
	insertY_AC(13, 8, 16, 65512);
	insertY_AC(13, 9, 16, 65513);
	insertY_AC(13, 10, 16, 65514);
	insertY_AC(14, 1, 16, 65515);
	insertY_AC(14, 2, 16, 65516);
	insertY_AC(14, 3, 16, 65517);
	insertY_AC(14, 4, 16, 65518);
	insertY_AC(14, 5, 16, 65519);
	insertY_AC(14, 6, 16, 65520);
	insertY_AC(14, 7, 16, 65521);
	insertY_AC(14, 8, 16, 65522);
	insertY_AC(14, 9, 16, 65523);
	insertY_AC(14, 10, 16, 65524);
	insertY_AC(15, 0, 11, 2041);
	insertY_AC(15, 1, 16, 65525);
	insertY_AC(15, 2, 16, 65526);
	insertY_AC(15, 3, 16, 65527);
	insertY_AC(15, 4, 16, 65528);
	insertY_AC(15, 5, 16, 65529);
	insertY_AC(15, 6, 16, 65530);
	insertY_AC(15, 7, 16, 65531);
	insertY_AC(15, 8, 16, 65532);
	insertY_AC(15, 9, 16, 65533);
	insertY_AC(15, 10, 16, 65534);

	//色度 直流
	insertC_DC(0, 0, 2,0 );
	insertC_DC(0, 1, 2, 1);
	insertC_DC(0, 2,2, 2);
	insertC_DC(0,3, 3, 6);
	insertC_DC(0, 4, 4, 14);
	insertC_DC(0, 5, 5, 30);
	insertC_DC(0, 6, 6, 62);
	insertC_DC(0, 7, 7, 126);
	insertC_DC(0, 8, 8, 254);
	insertC_DC(0, 9, 9, 510);
	insertC_DC(0, 10, 10, 1022);
	insertC_DC(0, 11, 11, 2046);

	//色度 交流
	insertC_AC(0, 0, 2, 0);
	insertC_AC(0, 1, 2, 1);
	insertC_AC(0, 2, 3, 4);
	insertC_AC(0, 3, 4, 10);
	insertC_AC(0, 4, 5, 24);
	insertC_AC(0, 5, 5, 25);
	insertC_AC(0, 6, 6, 56);
	insertC_AC(0, 7, 7, 120);
	insertC_AC(0, 8, 9, 500);
	insertC_AC(0, 9, 10, 1014);
	insertC_AC(0, 10, 12, 4084);
	insertC_AC(1, 1, 4, 11);
	insertC_AC(1, 2, 6, 57);
	insertC_AC(1, 3, 8, 246);
	insertC_AC(1, 4, 9, 501);
	insertC_AC(1, 5, 11, 2038);
	insertC_AC(1, 6, 12, 4085);
	insertC_AC(1, 7, 16, 65416);
	insertC_AC(1, 8, 16, 65417);
	insertC_AC(1, 9, 16, 65418);
	insertC_AC(1, 10, 16, 65419);
	insertC_AC(2, 1, 5, 26);
	insertC_AC(2, 2, 8, 247);
	insertC_AC(2, 3, 10, 1015);
	insertC_AC(2, 4, 12, 4086);
	insertC_AC(2, 5, 15, 32706);
	insertC_AC(2, 6, 16, 65420);
	insertC_AC(2, 7, 16, 65421);
	insertC_AC(2, 8, 16, 65422);
	insertC_AC(2, 9, 16, 65423);
	insertC_AC(2, 10, 16, 65424);
	insertC_AC(3, 1, 5, 27);
	insertC_AC(3, 2, 8, 248);
	insertC_AC(3, 3, 10, 1016);
	insertC_AC(3, 4, 12, 4087);
	insertC_AC(3, 5, 16, 65425);
	insertC_AC(3, 6, 16, 65426);
	insertC_AC(3, 7, 16, 65427);
	insertC_AC(3, 8, 16, 65428);
	insertC_AC(3, 9, 16, 65429);
	insertC_AC(3, 10, 16, 65430);
	insertC_AC(4, 1, 6, 58);
	insertC_AC(4, 2, 9, 502);
	insertC_AC(4, 3, 16, 65431);
	insertC_AC(4, 4, 16, 65432);
	insertC_AC(4, 5, 16, 65433);
	insertC_AC(4, 6, 16, 65434);
	insertC_AC(4, 7, 16, 65435);
	insertC_AC(4, 8, 16, 65436);
	insertC_AC(4, 9, 16, 65437);
	insertC_AC(4, 10, 16, 65438);
	insertC_AC(5, 1, 6, 59);
	insertC_AC(5, 2, 10, 1017);
	insertC_AC(5, 3, 16, 65439);
	insertC_AC(5, 4, 16, 65440);
	insertC_AC(5, 5, 16, 65441);
	insertC_AC(5, 6, 16, 65442);
	insertC_AC(5, 7, 16, 65443);
	insertC_AC(5, 8, 16, 65444);
	insertC_AC(5, 9, 16, 65445);
	insertC_AC(5, 10, 16, 65446);
	insertC_AC(6, 1, 7, 121);
	insertC_AC(6, 2, 11, 2039);
	insertC_AC(6, 3, 16, 65447);
	insertC_AC(6, 4, 16, 65448);
	insertC_AC(6, 5, 16, 65449);
	insertC_AC(6, 6, 16, 65450);
	insertC_AC(6, 7, 16, 65451);
	insertC_AC(6, 8, 16, 65452);
	insertC_AC(6, 9, 16, 65453);
	insertC_AC(6, 10, 16, 65454);
	insertC_AC(7, 1, 7, 122);
	insertC_AC(7, 2, 11, 2040);
	insertC_AC(7, 3, 16, 65455);
	insertC_AC(7, 4, 16, 65456);
	insertC_AC(7, 5, 16, 65457);
	insertC_AC(7, 6, 16, 65458);
	insertC_AC(7, 7, 16, 65459);
	insertC_AC(7, 8, 16, 65460);
	insertC_AC(7, 9, 16, 65461);
	insertC_AC(7, 10, 16, 65462);
	insertC_AC(8, 1, 8, 249);
	insertC_AC(8, 2, 16, 65463);
	insertC_AC(8, 3, 16, 65464);
	insertC_AC(8, 4, 16, 65465);
	insertC_AC(8, 5, 16, 65466);
	insertC_AC(8, 6, 16, 65467);
	insertC_AC(8, 7, 16, 65468);
	insertC_AC(8, 8, 16, 65469);
	insertC_AC(8, 9, 16, 65470);
	insertC_AC(8, 10, 16, 65471);
	insertC_AC(9, 1, 9, 503);
	insertC_AC(9, 2, 16, 65472);
	insertC_AC(9, 3, 16, 65473);
	insertC_AC(9, 4, 16, 65474);
	insertC_AC(9, 5, 16, 65475);
	insertC_AC(9, 6, 16, 65476);
	insertC_AC(9, 7, 16, 65477);
	insertC_AC(9, 8, 16, 65478);
	insertC_AC(9, 9, 16, 65479);
	insertC_AC(9, 10, 16, 65480);
	insertC_AC(10, 1, 9, 504);
	insertC_AC(10, 2, 16, 65481);
	insertC_AC(10, 3, 16, 65482);
	insertC_AC(10, 4, 16, 65483);
	insertC_AC(10, 5, 16, 65484);
	insertC_AC(10, 6, 16, 65485);
	insertC_AC(10, 7, 16, 65486);
	insertC_AC(10, 8, 16, 65487);
	insertC_AC(10, 9, 16, 65488);
	insertC_AC(10, 10, 16, 65489);
	insertC_AC(11, 1, 9, 505);
	insertC_AC(11, 2, 16, 65490);
	insertC_AC(11, 3, 16, 65491);
	insertC_AC(11, 4, 16, 65492);
	insertC_AC(11, 5, 16, 65493);
	insertC_AC(11, 6, 16, 65494);
	insertC_AC(11, 7, 16, 65495);
	insertC_AC(11, 8, 16, 65496);
	insertC_AC(11, 9, 16, 65497);
	insertC_AC(11, 10, 16, 65498);
	insertC_AC(12, 1, 9, 506);
	insertC_AC(12, 2, 16, 65499);
	insertC_AC(12, 3, 16, 65500);
	insertC_AC(12, 4, 16, 65501);
	insertC_AC(12, 5, 16, 65502);
	insertC_AC(12, 6, 16, 65503);
	insertC_AC(12, 7, 16, 65504);
	insertC_AC(12, 8, 16, 65505);
	insertC_AC(12, 9, 16, 65506);
	insertC_AC(12, 10, 16, 65507);
	insertC_AC(13, 1, 11, 2041);
	insertC_AC(13, 2, 16, 65508);
	insertC_AC(13, 3, 16, 65509);
	insertC_AC(13, 4, 16, 65510);
	insertC_AC(13, 5, 16, 65511);
	insertC_AC(13, 6, 16, 65512);
	insertC_AC(13, 7, 16, 65513);
	insertC_AC(13, 8, 16, 65514);
	insertC_AC(13, 9, 16, 65515);
	insertC_AC(13, 10, 16, 65516);
	insertC_AC(14, 1, 14, 16352);
	insertC_AC(14, 2, 16, 65517);
	insertC_AC(14, 3, 16, 65518);
	insertC_AC(14, 4, 16, 65519);
	insertC_AC(14, 5, 16, 65520);
	insertC_AC(14, 6, 16, 65521);
	insertC_AC(14, 7, 16, 65522);
	insertC_AC(14, 8, 16, 65523);
	insertC_AC(14, 9, 16, 65524);
	insertC_AC(14, 10, 16, 65525);
	insertC_AC(15, 0, 10, 1018);
	insertC_AC(15, 1, 15, 32707);
	insertC_AC(15, 2, 16, 65526);
	insertC_AC(15, 3, 16, 65527);
	insertC_AC(15, 4, 16, 65528);
	insertC_AC(15, 5, 16, 65529);
	insertC_AC(15, 6, 16, 65530);
	insertC_AC(15, 7, 16, 65531);
	insertC_AC(15, 8, 16, 65532);
	insertC_AC(15, 9, 16, 65533);
	insertC_AC(15, 10, 16, 65534);

	printf("Y_AC_floor_num[15]=%d\n", Y_AC_floor_num[15]);

}
void HuffmanTable::insertY_DC(int high, int low, int bit_num, int bits) {
	int num = (high << 4) + low;
	Bits b(bit_num, bits);
	Y_DC_table.insert(make_pair(num, b));
	Y_DC_floor_num[bit_num]++;
	Y_DC_queue.push(make_pair(bits,num));
}
void HuffmanTable::insertY_AC(int high, int low, int bit_num, int bits) {
	int num = (high << 4) + low;
	Bits b(bit_num, bits);
	Y_AC_table.insert(make_pair(num, b));
	Y_AC_floor_num[bit_num]++;
	Y_AC_queue.push(make_pair(bits, num));
}
void HuffmanTable::insertC_DC(int high, int low, int bit_num, int bits) {
	int num = (high << 4) + low;
	Bits b(bit_num, bits);
	C_DC_table.insert(make_pair(num, b));
	C_DC_floor_num[bit_num]++;
	C_DC_queue.push(make_pair(bits, num));
}
void HuffmanTable::insertC_AC(int high, int low, int bit_num, int bits) {
	int num = (high << 4) + low;
	Bits b(bit_num, bits);
	C_AC_table.insert(make_pair(num, b));
	C_AC_floor_num[bit_num]++;
	C_AC_queue.push(make_pair(bits, num));
}
Bits HuffmanTable::encodeY_DC(int num) {
	return Y_DC_table[num];
}
Bits HuffmanTable::encodeY_AC(int num) {
	return Y_AC_table[num];
}
Bits HuffmanTable::encodeC_DC(int num) {
	return C_DC_table[num];
}
Bits HuffmanTable::encodeC_AC(int num) {
	return C_AC_table[num];
}
list<Bits> HuffmanTable::export_Y_DC_Bits() {
	list<Bits> bitsList;
	Bits b1(8, 255);
	Bits b2(8, 196);
	Bits segSize(16, 19 + Y_DC_queue.size());
	bitsList.push_back(b1);
	bitsList.push_back(b2);
	bitsList.push_back(segSize);

	Bits bits_zeros(3, 0);
	Bits bits_type(1, 0);
	Bits bits_num(4, 0);

	bitsList.push_back(bits_zeros);
	bitsList.push_back(bits_type);
	bitsList.push_back(bits_num);
	for (int i = 1; i <= 16; i++) {
		Bits b(8, Y_DC_floor_num[i]);
		bitsList.push_back(b);
	}
	while (Y_DC_queue.size() > 0) {
		int value = Y_DC_queue.top().second;
		Y_DC_queue.pop();
		Bits b(8, value);
		bitsList.push_back(b);
	}
	return bitsList;
}

list<Bits> HuffmanTable::export_Y_AC_Bits() {
	list<Bits> bitsList;
	Bits b1(8, 255);
	Bits b2(8, 196);
	Bits segSize(16, 19 + Y_AC_queue.size());
	bitsList.push_back(b1);
	bitsList.push_back(b2);
	bitsList.push_back(segSize);

	Bits bits_zeros(3, 0);
	Bits bits_type(1, 1);
	Bits bits_num(4, 0);

	bitsList.push_back(bits_zeros);
	bitsList.push_back(bits_type);
	bitsList.push_back(bits_num);
	for (int i = 1; i <= 16; i++) {
		Bits b(8, Y_AC_floor_num[i]);
		bitsList.push_back(b);
	}
	while (Y_AC_queue.size() > 0) {
		int value = Y_AC_queue.top().second;
		Y_AC_queue.pop();
		Bits b(8, value);
		bitsList.push_back(b);
	}
	return bitsList;
}

list<Bits> HuffmanTable::export_C_DC_Bits() {
	list<Bits> bitsList;
	Bits b1(8, 255);
	Bits b2(8, 196);
	Bits segSize(16, 19 + C_DC_queue.size());
	bitsList.push_back(b1);
	bitsList.push_back(b2);
	bitsList.push_back(segSize);

	Bits bits_zeros(3, 0);
	Bits bits_type(1, 0);
	Bits bits_num(4, 1);

	bitsList.push_back(bits_zeros);
	bitsList.push_back(bits_type);
	bitsList.push_back(bits_num);
	for (int i = 1; i <= 16; i++) {
		Bits b(8, C_DC_floor_num[i]);
		bitsList.push_back(b);
	}
	while (C_DC_queue.size() > 0) {
		int value = C_DC_queue.top().second;
		C_DC_queue.pop();
		Bits b(8, value);
		bitsList.push_back(b);
	}
	return bitsList;
}

list<Bits> HuffmanTable::export_C_AC_Bits() {
	list<Bits> bitsList;
	Bits b1(8, 255);
	Bits b2(8, 196);
	Bits segSize(16, 19 + C_AC_queue.size());
	bitsList.push_back(b1);
	bitsList.push_back(b2);
	bitsList.push_back(segSize);

	Bits bits_zeros(3, 0);
	Bits bits_type(1, 1);
	Bits bits_num(4, 1);

	bitsList.push_back(bits_zeros);
	bitsList.push_back(bits_type);
	bitsList.push_back(bits_num);
	for (int i = 1; i <= 16; i++) {
		Bits b(8, C_AC_floor_num[i]);
		bitsList.push_back(b);
	}
	while (C_AC_queue.size() > 0) {
		int value = C_AC_queue.top().second;
		C_AC_queue.pop();
		Bits b(8, value);
		bitsList.push_back(b);
	}
	return bitsList;
}

list<Bits> HuffmanTable::exportAll() {
	list<Bits> bitsList;
	list<Bits> Y_DC_bits = export_Y_DC_Bits();
	list<Bits> Y_AC_bits = export_Y_AC_Bits();
	list<Bits> C_DC_bits = export_C_DC_Bits();
	list<Bits> C_AC_bits = export_C_AC_Bits();
	bitsList.splice(bitsList.end(), Y_DC_bits);
	bitsList.splice(bitsList.end(), Y_AC_bits);
	bitsList.splice(bitsList.end(), C_DC_bits);
	bitsList.splice(bitsList.end(), C_AC_bits);
	return bitsList;
}

list<HuffmanNode> HuffmanTable::encodeY(list<BITNode> bitNodeList) {
	//printf("bbb\n");
	//3.编码
	list<HuffmanNode> huffmanNodeList;
	list<BITNode>::iterator iter;
	
	for (iter = bitNodeList.begin(); iter != bitNodeList.end(); iter++) {
		HuffmanNode huffmanNode;
		huffmanNode.setCode(iter->getCode());

		if (iter->isDC()) {
			huffmanNode.setLength(encodeY_DC(iter->getLength()));
		}
		else {
			huffmanNode.setLength(encodeY_AC(iter->getLength()));
		}
		huffmanNodeList.push_back(huffmanNode);
		//huffmanNode.print();
	}
	//printf("\n");
	return huffmanNodeList;
}

list<HuffmanNode> HuffmanTable::encodeC(list<BITNode> bitNodeList) {
	//printf("aaa\n");
	//3.编码
	list<HuffmanNode> huffmanNodeList;
	list<BITNode>::iterator iter;
	for (iter = bitNodeList.begin(); iter != bitNodeList.end(); iter++) {
		HuffmanNode huffmanNode;
		huffmanNode.setCode(iter->getCode());

		if (iter->isDC()) {
			huffmanNode.setLength(encodeC_DC(iter->getLength()));
		}
		else {
			huffmanNode.setLength(encodeC_AC(iter->getLength()));
		}
		huffmanNodeList.push_back(huffmanNode);
		//huffmanNode.print();
	}
	//printf("\n");
	return huffmanNodeList;
}