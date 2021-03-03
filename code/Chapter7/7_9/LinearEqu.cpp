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

inline void swap(double& v1, double& v2) {
	double temp = v1;
	v1 = v2;
	v2 = temp;
}

bool LinearEqu::solve() {
	int* js = new int[getSize()];
	for (int k = 0; k < getSize(); k++) {
		int is;
		double max;
		for (int i = k; i < getSize(); i++) {
			for (int j = k; j < getSize(); j++) {
				double t = fabs(element(i, j));
				if (t > max) {
					max = t;
					js[k] = j;
					is = i;
				}
			}
			if (max == 0) {
				delete[] js;
				return false;
			}
			else {
				if (js[k] != k) {
					for (int i = 0; i < getSize(); i++) {
						swap(element(i, k), element(i, js[k]));
					}
				}
				if (is != k) {
					for (int j = k; j < getSize(); j++) {
						swap(element(k, j), element(is, j));
					}
				}
				swap(sums[k], sums[is]);
			}
		}

		double major = element(k, k);
		for (int j = k + 1; j < getSize(); j++) {
			element(k, j) /= major;
		}
		sums[k] /= major;
		for (int i = k + 1; i < getSize(); i++) {
			for (int j = k + 1; j < getSize(); j++) {
				element(i, j) -= element(i, k) * element(k, j);
			}
			sums[i] -= element(i, k) * sums[k];
		}
	}


}