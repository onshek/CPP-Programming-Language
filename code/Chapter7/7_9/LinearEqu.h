#ifndef _LINEAR_EQU_H
#define _LINEAR_EQU_H
#include "Matrix.h"

class LinearEqu :public Matrix {
public:
	LinearEqu(int size = 2);
	~LinearEqu();
	void setLinearEqu(const double* a, const double* b);
	bool solve();
	void printLinearEqu() const;
	void printSolution() const;
private:
	double* sums;
	double* solution;
};

#endif // !_LINEAR_EQU_H