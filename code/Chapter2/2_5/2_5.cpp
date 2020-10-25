#include <iostream>
using namespace std;

int main() {
    int i = 0, sum = 0;
    while (i <= 10) {
        sum += i;
        i++;
    }
    cout << "sum=" << sum << endl;
    return 0;
}
