#ifndef CALCULATOR H
#define CALCULATOR H
#include "Stack.h"                           //����У��ģ�嶨���ļ�

class Calculator {                           //��������
private:
	Stack<double> s;                         //������ջ
	void enter(double num);                  //�������� num ѹ��ջ
	//��������������������ջ������ opndl opnd2 ��
	bool getTwoOperands(double& opnd1, double& opnd2);
	void compute(char op);                   //ִ���ɲ����� op ָ��������
public:
	void run();                              //���м���������
	void clear();                            //��ղ�����ջ
};

#endif // !CALCULATOR H
