#pragma once
#include <string>
#include <stdio.h>
using namespace std;
class ImageInput {
public:
	void readImage(const char* path,double **src,int *h,int *w);
	void readQTable(const char* path, int** src);
};