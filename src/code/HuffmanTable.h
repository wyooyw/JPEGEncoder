#pragma once
#include "Bits.h"
#include <map>
#include <list>
#include <queue>
#include "BITNode.h"
#include "HuffmanNode.h"
class HuffmanTable {
private:
	map<int, Bits> Y_DC_table;
	map<int, Bits> Y_AC_table;
	map<int, Bits> C_DC_table;
	map<int, Bits> C_AC_table;
	int Y_DC_floor_num[17];
	int Y_AC_floor_num[17];
	int C_DC_floor_num[17];
	int C_AC_floor_num[17];
	priority_queue<pair<int,int>,vector<pair<int, int> >,greater<pair<int, int> > > Y_DC_queue;
	priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > Y_AC_queue;
	priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > C_DC_queue;
	priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > C_AC_queue;
	void insertY_DC(int high, int low, int bit_num, int bits);
	void insertY_AC(int high, int low, int bit_num, int bits);
	void insertC_DC(int high, int low, int bit_num, int bits);
	void insertC_AC(int high, int low, int bit_num, int bits);
	list<HuffmanNode> encode(list<BITNode> bitNodeList);
public:
	HuffmanTable();
	Bits encodeY_DC(int num);
	Bits encodeY_AC(int num);
	Bits encodeC_DC(int num);
	Bits encodeC_AC(int num);
	list<HuffmanNode> encodeY(list<BITNode> bitNodeList);
	list<HuffmanNode> encodeC(list<BITNode> bitNodeList);
	list<Bits> exportAll();
	list<Bits> export_Y_DC_Bits();
	list<Bits> export_Y_AC_Bits();
	list<Bits> export_C_DC_Bits();
	list<Bits> export_C_AC_Bits();
};