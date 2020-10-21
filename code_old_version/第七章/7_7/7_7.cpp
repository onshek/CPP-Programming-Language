#include <iostream>
using namespace std;

class Base0 {
public:
	int var0;
	void funO() {
		cout << "Member of BaseO" << endl;
	}
};

class Base1 : public Base0 {
public:
	int var1;
};

class Base2 : public Base0 {
public:
	int var2;
};

class Derived : public Base1, public Base2 {
public:
	int var;
	void funO() {
		cout << "Member of Derived" << endl;
	}
};

int main() {
	Derived d;
	d.Base1::var0 = 2;
	d.Base1::funO();
	d.Base2::var0 = 3;
	d.Base2::funO();

	return 0;
}