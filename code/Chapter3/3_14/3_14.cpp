#include <iostream>
using namespace std;

const double PI = 3.14159265358979;

// 内联函数，根据圆的半径计算其面积
inline double calArea(double radius) {
    return PI * radius * radius;
}

int main() {
    double r = 3.0;
    double area = calArea(r);
    cout << area << endl;
    return 0;
}
