#pragma once
#include "byte.h"
#include "Bits.h"
#include<list>
#include <iostream>
#include <fstream>
using namespace std;
class BitsWriter {
private:
	string path;
public:
	BitsWriter(string filepath);
	void append(list<Bits> bitsList);
	void write(list<Bits> bitsList);
};