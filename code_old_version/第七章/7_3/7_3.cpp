#include <iostream>
using namespace std;

class Base1 {
public:
	void dispaly() const {
		cout << "Base1::display()" << endl;
	}
};

class Base2 : public Base1 {
public:
	void dispaly() const {
		cout << "Base2::display()" << endl;
	}
};

class Derived : public Base2 {
public:
	void display() const {
		cout << "Derived::display()" << endl;
	}
};

void fun(Base1 *ptr) {
	ptr->dispaly();
}

int main() {
	Base1 base1;
	Base2 base2;
	Derived derived;

	// 注意这里教材的结果写错了
	fun(&base1);
	fun(&base2);
	fun(&derived);

	return 0;
}