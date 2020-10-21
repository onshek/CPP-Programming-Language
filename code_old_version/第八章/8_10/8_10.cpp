#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
	virtual ~Base() {}
};

class Derived: public Base {};

void fun(Base* b) {
	const type_info& info1 = typeid(b);
	const type_info& info2 = typeid(*b);
	cout << "typeid (b) : " << info1.name() << endl;
	cout << "typeid (* b): " << info2.name() << endl;

	if (info2 == typeid(Base))
		cout << "A base class!" << endl;
}

int main() {
	Base b;
	fun(&b);
	Derived d;
	fun(&d);
	return 0;
}