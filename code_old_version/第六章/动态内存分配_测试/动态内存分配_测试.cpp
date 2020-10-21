/*
c++中new是如何动态的分配内存的？int *p;p=new int [5] 5不是在写程序的时候自己填的么？这怎么叫动态分配？ - 刘项的回答 - 知乎
https://www.zhihu.com/question/23378130/answer/24395022
*/

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    int n;
    int* p;
    std::cout << "Please input n=";
    std::cin >> n;
    p = new int[n];

    for (int i = 0; i < n; i++) {
        p[i] = i;
        std::cout << p[i] << " ";
    }
}
