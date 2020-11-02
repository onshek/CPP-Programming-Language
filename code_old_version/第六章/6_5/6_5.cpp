#include <iostream>
using namespace std;

int main() {
	int i = 123;
	int* ptr = &i;
	i = 10;
	cout << "i=" << i << endl;
	cout << "*ptr=" << *ptr << endl;
	return 0;
}