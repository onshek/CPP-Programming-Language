#include <list>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string names1[] = { "Alice", "Helen", "Lucy", "Susan" };
	string names2[] = { "Bob", "David" ,"Levin", "Mike" };
	list<string> s1(names1, names1 + 4);                  //用 names1 数组的内容构造列表 sl
	list<string> s2(names2, names2 + 4);                  //用 names2 数组的内容构造列表 s2

	//将 sl 的第一个元素放到 s2 的最后
	s2.splice(s2.end(), s1, s1.begin());
	list<string>::iterator iter1 = s1.begin();            //iter1 指向 sl 首
	advance(iter1, 2);
	list<string>::iterator iter2 = s2.begin();            //iter2 指向 s2 首
	++iter2;                                              //iter2 前进 1 个元素，它将指向 s2 第 2 个元素
	list<string>::iterator iter3 = iter2;                 //用 iter2 初始化 iter3
	advance(iter3, 2);                                    //iter3 前进 2 个元素，它将指向 s2 第 4 个元素
	//将 [iter2 iter3) 范围内的结点接到 sl 中 iter1 指向的结点前
	s1.splice(iter1, s2, iter2, iter3);	
	
	// 分别将 s1, s2 输出
	copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	
	return 0;
}