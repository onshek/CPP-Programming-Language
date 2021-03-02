#include "LinearEqu.h"
#include <iostream>
#include <cmath>
using namespace std;

LinearEqu::LinearEqu(int size/*=2*/) :Matrix(size) {
	sums = new double[size];
	solution = new double[size];
}

LinearEqu::~LinearEqu() {
	delete[] sums;
	delete[] solution;
}

void LinearEqu::printLinearEqu() const {
	cout << "The Line eqution is:" << endl;
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {
			cout << element(i, j) << " ";
		}
		cout << "    " << sums[i] << endl;
	}
}

void LinearEqu::printSolution() const {
	cout << "The Result is: " << endl;
	for (int i = 0; i < getSize(); i++) {
		cout << "X[" << i << "]=" << solution[i] << endl;
	}
}


