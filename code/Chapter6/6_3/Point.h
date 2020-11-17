#ifndef _POINT_H
#define _POINT_H

class Point{
public:
    Point();
    Point(int x, int y);
    ~Point();
    void move(int newX, int newY);
    int getX() {return x;}
    int getY() {return  y;}
private:
    int x, y;
};
#endif // _POINT_H
