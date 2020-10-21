#include <iostream>

void func1(int* A, int n) {
    std::cout << "func1: ";
    for (int i = 0; i < n; i++) {
        std::cout << A[n] << " ";
    }
}

void func2(int A[], int n) {
    std::cout << "func2: ";
    for (int i = 0; i < n; i++) {
        std::cout << A[n] << " ";
    }
}

int main()
{
    int k = 3;
    int a[5] = { 1, 2, 3, 4, 5 };
    int* b = new int[5]();
    func1(a, 3);
    func2(a, 3);
    func1(b, 3);
    func2(b, 3);
    return 0;
}
