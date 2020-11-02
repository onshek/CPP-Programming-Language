//这是我额外的尝试，并非课程中所有
//笔记位于 C:\Users\honfu\OneDrive - alu.suda.edu.cn\Notes\20200316_C++多继承和虚基类.txt

#include <iostream>
using namespace std;

class Base0 {
public:
	int var0;
	void fun0() { cout << "Member of Base0" << endl; }
	~Base0() { cout << "Destructing Base0, var0=" << var0 << endl; }
};

class Base1 : virtual public Base0 {
public:
	int var1;
	~Base1() { cout << "Destructing Base1, var0=" <<var0 << endl; }
};

class Base2 : virtual public Base0 {
public:
	int var2;
	~Base2() { cout << "Destructing Base2, var0=" << var0 << endl; }
};

class Derived : public Base1, public Base2 {
public:
	int var;
	~Derived() { cout << "Destructing Derived, var0=" << var0 << endl; }
};

int main() {
	Derived d;
	d.var0 = 2;
	d.fun0();
	return 0;
}