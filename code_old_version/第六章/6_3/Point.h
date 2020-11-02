#ifndef _POINT_H
#define _POINT_H
class Point {
public:
	Point();
	Point(int x, int y);
	~Point();
	void move(int newX, int newY);
	int getX() const { return x; }  // 内联函数
	int getY() const { return y; }  // 内联函数
	static void showCount();  // 静态函数成员
private:
	int x, y;
};

#endif
