#include <iostream>
using namespace std;

class Test {
public:
    inline void printA() {
        cout << "func: printA" << endl;
    }
    void printB() { // 隐式声明内联函数
        cout << "func: printB" << endl;
    }
    inline void printC();
    void printD();
};

inline void Test::printC() {
    cout << "func: printC" << endl;
}

inline void Test::printD() {
    cout << "func: printD" << endl;
}

int main() {
    Test test;
    test.printA();
    test.printB();
    test.printC();
    test.printD();
    return 0;
}
