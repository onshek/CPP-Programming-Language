#include <iostream>
#include <numeric>
using namespace std;

class MultClass {
public:
	int operator() (int x, int y)const { return x * y; }
};

int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	const int N = sizeof(a) / sizeof(int);
	cout << "The result by multipling all elemets in a is "
		<< accumulate(a, a + N, 1, MultClass())
		<< endl;
	return 0;
}