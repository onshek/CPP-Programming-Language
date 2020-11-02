// 对应 7.5.3 虚基类及其派生类构造函数
#include <iostream>
using namespace std;

class Base0 {
public:
	Base0(int var) : var(var) {};
	int var;
	void fun0() { cout << "Member of Base0" << endl; }
};

class Base1 : virtual public Base0 {
public:
	Base1(int var) :Base0(var) {};
	int var1;
};

class Base2 : virtual public Base0 {
public:
	Base2(int var) : Base0(var) {};
	int var2;
};

class Derived : public Base1, public Base2 {
public:
	Derived(int var) : Base0(var), Base1(var), Base2(var) {};
	int var;
	void fun() { cout << "Member of Derived" << endl; }
};

int main() {
	Derived d(1);
	d.var = 2;
	d.fun();
	return 0;
}