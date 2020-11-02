#ifndef CALCULATOR H
#define CALCULATOR H
#include "Stack.h"                           //包含校类模板定义文件

class Calculator {                           //计算器类
private:
	Stack<double> s;                         //操作数栈
	void enter(double num);                  //将操作数 num 压入栈
	//连续将两个操作数弹出栈，放在 opndl opnd2 中
	bool getTwoOperands(double& opnd1, double& opnd2);
	void compute(char op);                   //执行由操作符 op 指定的运算
public:
	void run();                              //运行计算器程序
	void clear();                            //清空操作数栈
};

#endif // !CALCULATOR H
