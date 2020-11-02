#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

/*20200426，此段代码逐句调试没有问题，但无法直接执行*/
int main() {
	map<string, int> courses;
	//将课程信息插入 courses 映射中
	courses.insert(make_pair("CSAPP", 3));
	courses.insert(make_pair("C++", 2));
	courses.insert(make_pair("CSARCH", 4));
	courses.insert(make_pair("COMPILER", 4));
	courses.insert(make_pair("OS", 5));

	int n = 3;                                //剩下的可选次数
	int sum = 0;                              //学分总和

	while (n > 0) {
		string name;
		cin >> name;                          //输入课程名称
 		map<string, int>::iterator iter = courses.find(name);    //查找课程
		if (iter == courses.end()) { //判断是否找到
			cout << name << " is not availabe" << endl;
		}
		else {
			sum += iter->second;              //累加学分
			courses.erase(iter);              //将刚选过的课程从映射中删除
			n--;
		}
	}
	
	cout << "Total credit: " << sum << endl;  //输出总学分
	return 0;
}