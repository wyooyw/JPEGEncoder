
#include "BitsWriter.h"

BitsWriter::BitsWriter(string filepath) {
	path = filepath;
}
void BitsWriter::append(list<Bits> bitsList) {
	ofstream outFile(path, ios::app | ios::binary);

	list<Bits>::iterator iter;

	for (iter = bitsList.begin(); iter != bitsList.end(); iter++) {
		bits_unit bits = iter->getBits();
		bits = BigLittleSwap32(bits);
		outFile.write((char*)&bits, sizeof(bits_unit));
	}

	outFile.close();
}
void BitsWriter::write(list<Bits> bitsList) {
	ofstream outFile(path, ios::out | ios::binary);

	list<Bits>::iterator iter;

	for (iter = bitsList.begin(); iter != bitsList.end(); iter++) {
		bits_unit bits = iter->getBits();
		bits = BigLittleSwap32(bits);
		outFile.write((char*)&bits, sizeof(bits_unit));
	}

	outFile.close();
}