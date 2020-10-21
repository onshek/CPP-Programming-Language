#include <iostream>
using namespace std;

class Point {
public:
	Point(int x, int y) : x(x), y(y) {
		count++;
	}
	Point(const Point &p) : x(p.x), y(p.y) {
		count++;
	}	
	~Point() { count--; }

	int getX() const { return x; }
	int getY() const { return y; }

	static void showCount() {
		cout << "Object count=" << count << endl;
	}
private:
	int x, y;
	static int count;
};

int Point::count = 0;

int main() {
	void (*funcPtr)() = Point::showCount;

	Point a(4, 5);
	cout << "Point a: " << a.getX() << ", " << a.getY() << endl;
	funcPtr();

	Point b(a);
	cout << "Point b: " << b.getX() << ", " << b.getY() << endl;
	funcPtr();

	return 0;
}