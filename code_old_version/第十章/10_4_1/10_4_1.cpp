// 10_4_1.cpp : P416-P417
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    vector<int> s;                                //定义一个向量容器 s
    s.reserve(3);                                 //确保 s 至少具有 3 的容量
    s.push_back(1);                               //将元素 1 加入 s 的末尾
    s.push_back(2);                               //将元素 2 加入 s 的末尾
    vector<int>::iterator iter1 = s.begin();      //iterl 是指向容器第 1 个元素的迭代器
    int* p1 = &(s[0]);                            //pl 是指向容器第 1 个元素的指针
    vector<int>::iterator iter2 = s.begin() + 1; //iter2 是指向容器第 2 个元素的迭代器
    int* p2 = &s[1];                              //p2 是指向容器第 2 个元素的指针
    
    s.insert(s.begin() + 1, 3);                   //在容器的第 2 个元素前插入新的元素 3
    cout << *iter1 << " " << *p1 << endl;         //这是正确的，可以得到结果 "1"
    cout << *iter2 << " " << *p2 << endl;         //这是错误的，iter2、p2 均已失效，结果不确定
    return 0;
}
