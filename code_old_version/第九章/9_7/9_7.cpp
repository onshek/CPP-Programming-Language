#include <iostream>;
#include "LinkedList.h"
using namespace std;

int main() {
	LinkedList<int> list;

	//输入 10 个整数依次向表头插入
	for (int i = 0; i < 10; i++) {
		int item;
		cin >> item;
		list.insertFront(item);
	}

	//输出链表
	cout << "List: ";
	list.reset();

}