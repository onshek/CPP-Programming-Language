#include <iostream>
#include <cmath>
#include "Rectangle.h"

using namespace std;

int main() {
    Rectangle rect;
    rect.initRectangle(2, 3, 20, 10);
    rect.move(3, 2);
    cout << "The data of rect(x, y, w, h): " << endl;
    cout << rect.getX() << ", "
         << rect.getY() << ", "
         << rect.getW() << ", "
         << rect.getH() << endl;
    return 0;
}
