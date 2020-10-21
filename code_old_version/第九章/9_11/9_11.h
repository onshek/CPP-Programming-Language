#ifndef HEADER_9_11_H
#define HEADER_9_11_H


//��ֱ�Ӳ������򷨶�����a�е�Ԫ�ؽ�����������
template<class T>
void insertSort(T a[], int n) {
	int i, j;
	T temp;
	
	//���±�Ϊ 1 ~ n-1 ��Ԫ��������뵽�������������ʵ���λ��
	for (int i = 1; i < n; i++) {
		//a[i-1] ��ʼ�� a[0] ����ɨ���Ԫ�أ�Ѱ���ʵ�λ�ò��� a[i]
		int j = i;
		T temp = a[i];
		while (j > 0 && temp < a[j - 1]) {
			//����Ƚϣ�ֱ�� temp >= a[j-1] ʱ�� ����Ӧ�����λ��
			//���ﵽ j==O ����0��Ӧ�����λ��
			a[j] = a[j - 1];               //��Ԫ��������ƣ��Ա��ҵ�����λ��ʱ����������
			j--;
		}
		//����λ�����ҵ�����������
		a[j] = temp;
	}
}

#endif // !HEADER_9_11_H
