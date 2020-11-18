#include <iostream>

using namespace std;


int main() {
    void *pv;
    int i = 5;
    pv = &i;
    int *point = static_cast<int *>(pv);
    cout << " * point=" << *point << endl;
    return 0;
}
