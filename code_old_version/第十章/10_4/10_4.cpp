#include <iostream>
#include <list>
#include <deque>
#include <iterator>
using namespace std;

/*TODO　此段代码有问题，尚未解决，20200420*/
//输出指定的整型顺序容器的元素
template <class T>
void printContrainer(const char* msg, const T& s) {
	cout << msg << ": ";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main() {
	//从标准输入读入 10 个整数，将它们分别从 s 的头部加入
	deque<int> s;
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		s.push_front(x);
	}
	printContrainer("deque at first", s);
	//用 s 容器的内容的逆序构造列表容器 l
	list<int> l(s.rbegin(), s.rend());
	printContrainer("list at first", l);

	//将列表容器工的每相邻两个容器顺序颠倒
	list<int>::iterator iter = l.begin();
	while (iter != l.end()) {
		int v = *iter;                //得到一个元素
		iter = l.erase(iter);         //将该元素删除，得到指向下一个元素的迭代器
		l.insert(++iter, v);          //将刚刚删除的元素插入下一个位置
	}
	printContrainer("list at last", l);

	//用列表容器 l 的内容给 s 赋值，将 s 输出
	s.assign(l.begin(), l.end());
	printContrainer("deque at last", s);

	return 0;
}