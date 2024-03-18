#include "ImageInput.h"
void ImageInput::readImage(const char *path, double** src, int* w, int* h) {
	FILE* fp = fopen(path, "r");
	fscanf(fp, "%d", w);
	fscanf(fp,"%d",h);
	int total = (*w) * (*h) * 3;
	(*src) = (double*)malloc(sizeof(double)*total);
	double* ptr = *src;
	for (int i = 0; i < total; i++) {
		fscanf(fp,"%lf",ptr++);
	}
}

void ImageInput::readQTable(const char* path, int** src) {
	FILE* fp = fopen(path, "r");
	(*src) = (int*)malloc(sizeof(int) * 64);
	int* ptr = *src;
	for (int i = 0; i < 64; i++) {
		fscanf(fp, "%d", ptr++);
	}
}