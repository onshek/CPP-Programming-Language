#include <iostream>
using namespace std;

class Base1 {
public:
	Base1(int i) {
		cout << "Constructing Base1 " << i << endl;
	}
};

class Base2 {
public:
	Base2(int j) {
		cout << "Constructing Base2 " << j << endl;
	}
};

class Base3 {
public:
	Base3() {
		cout << "Constructing Base3 * " << endl;
	}
};

class Derived : public Base2, public Base1, public Base3 {
public:
	Derived(int a, int b, int c, int d) : Base1(a), number2(d), number1(c), Base2(b) {}
private:
	Base1 number1;
	Base2 number2;
	Base3 number3;
};

int main() {
	Derived obj(1, 2, 3, 4);
	return 0;
}