#include <iostream>
using namespace std;

class Point {
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {};
	int getX() const { return x; }
	int getY() const { return y; }
private:
	int x, y;
};

int main() {                                              // 主函数
	Point a(4, 5);										  // 定义对象 a
	Point* p = &a;                                        // 定义对象指针并初始化
	int (Point:: * funcPtr)() const = &Point::getX;       // 定义成员函数指针并初始化

	cout << "a.getX()=" << a.getX() << endl;
	cout << "p->getX()=" << p->getX() << endl;
	cout << "(a.*funcPtr)()=" << (a.*funcPtr)() << endl;
	cout << "(p->*funcPtr)()=" << (p->*funcPtr)() << endl;

	return 0;
}