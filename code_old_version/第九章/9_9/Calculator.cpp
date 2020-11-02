//Calculator.cpp
#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

void Calculator::enter(double num) {                    //将操作数 num 压入栈
	s.push(num);
}

//连续将两个操作数弹出栈，放在 opndl opnd2
//如果栈中没有两个操作数，则返回 false 并输出相关信息
bool Calculator::getTwoOperands(double& opnd1, double& opnd2) {
	if (s.isEmpty()) {                                  //检查栈是否为空
		cerr << "Missing operand! " << endl;
		return false;
	}
	opnd1 = s.pop();                                    //将右操作数弹出栈
	if (s.isEmpty()) {                                  //检查栈是否为空
		cerr << "Missing operand! " << endl;
		return false;
	} 
	opnd2 = s.pop();                                    //将左操作数弹出栈
	return true;
}

void Calculator::compute(char op) {                     //执行运算
	double operand1, operand2;
	bool result = getTwoOperands(operand1, operand2);   //将两个操作数弹出栈

	if (result) {                                       //如果成功，执行运算并将运算结果压入栈
		switch (op) {
		case '+':
			s.push(operand1 + operand2);
			break;
		case '-':
			s.push(operand1 - operand2);
			break;
		case '*':
			s.push(operand1 * operand2);
			break;
		case '/':
			if (operand2 == 0) {                         //检查除数是否为0
				cerr << "Divided by O! " << endl;
				s.clear();                               //除数为0时清空栈
			}
			else {
				s.push(operand1 / operand2);
			}
			break;	
		case '^':
			s.push(pow(operand1, operand2));
			break;
		default:
			cerr << "Unrecognized operator! " << endl;
			break;
		}
		cout << "=" << s.peek() << " ";                  //输出本次运算结果
	}
	else {
		s.clear();                                       //操作数不够，清空栈
	}
}

//工具函数，用于将字符串转换为实数
inline double stringToDouble(const string& str) {
	istringstream stream(str);                           //字符串输入流
	double result;
	stream >> result;
	return result;
}

void Calculator::run() {                                 //读入并处理后缀表达式
	string str;
	while (cin >> str, str != "q") {
		switch (str[0])
		{
		case 'c':                                        //遇 "c" 清空操作数栈
			s.clear();
			break;
		case '-':                                        //遇"-"需判断是减号还是负号
			if (str.size() > 1)
				enter(stringToDouble(str));              //若字符串长度>1，说明读到的是负数的负号
			else
				compute(str[0]);                         //将字符串转换为整数，压入栈
			break;
		case '+':
		case '*':
		case '/':
		case '^':
			compute(str[0]);
			break;
		default:                                         //若读入的是操作数，转换为整型后压入栈
			enter(stringToDouble(str));
			break;
		}
	}
}

void Calculator::clear() {                               //清空操作数栈
	s.clear();
}