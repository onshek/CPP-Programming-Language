#include "point.h"
#include <iostream>
using namespace std;

int main() {
    Point a(4, 5);
    cout << "Point A: " << a.getX() << ", " << a.getY();
    Point::showCount();

    Point b(a);
    cout << "Point B: " << b.getX() << ", " << b.getY();
    Point::showCount();

    return 0;
}