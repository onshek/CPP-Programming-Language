#include "Matrix.h"
#include <iostream>
using namespace std;


void Matrix::setMatrix(const double* values) {
	for (int i = 0; i < size * size; i++) {
		elements[i] = values[i];
	}
}

Matrix::Matrix(int size/*=2*/) :size(size) {
	elements = new double[size * size];
}

Matrix::~Matrix() {
	delete[] elements;
}

void Matrix::printMatrix() const {
	cout << "The Matrix is:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << element(i, j) << " ";
		}
		cout << endl;
	}
}