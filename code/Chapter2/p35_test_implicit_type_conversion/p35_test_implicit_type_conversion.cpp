// 用于测试运算符的自动类型转换
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    float fVal = 1.0;
    double dVal;
    int iVal = 3;
    unsigned long ulVal = 4;
    dVal = iVal * ulVal;
    cout << typeid(iVal * ulVal).name() << endl;
    cout << typeid(dVal).name() << endl;
    dVal = ulVal + fVal;
    cout << typeid(ulVal + fVal).name() << endl;
    cout << typeid(dVal).name() << endl;
    return 0;
}
