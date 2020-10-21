#include <iostream>
using namespace std;

int main() {
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	// 6_7_1
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	// 6_7_2
	for (int i = 0; i < 10; i++) {
		cout << *(a + i) << " ";
	}
	cout << endl;
	// 6_7_3
	for (int* p = a; p < (a + 10); p++) {
		cout << *p << " ";
	}
	cout << endl;
	return 0;
}