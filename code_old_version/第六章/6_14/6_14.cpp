#include <iostream>
using namespace std;

class Point {
public:
	Point(int x, int y) : x(x), y(y) {                   // 构造函数
		count++;
	}
	Point(const Point &p) : x(p.x + 1), y(p.y + 1) {     // 复制构造函数
		count++;
	}
	~Point() { count--; }                                // 析构函数       
	int getX() const { return x; }
	int getY() const { return y; }
	static int count;                                    // 声明静态数据成员
private:
	int x, y;
};

int Point::count = 0;

int main() {
	int* ptr = &Point::count;
	Point a(4, 5);
	cout << "Point a: " << a.getX() << ", " << a.getY() << endl;
	cout << "Object count=" << *ptr << endl;
	
	Point b(a);
	cout << "Point b: " << b.getX() << ", " << b.getY() << endl;
	cout << "Object count=" << *ptr << endl;

	Point c = b;
	cout << "Point c: " << c.getX() << ", " << c.getY() << endl;
	cout << "Object count=" << *ptr << endl;
}