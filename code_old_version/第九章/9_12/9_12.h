#ifndef HEADER_9_12_H
#define HEADER_9_12_H

//��������:����x,y��ֵ
template<class T>
void mySwap(T& x, T& y) {
	temp = x;
	x = y;
	y = temp;
}

//��ѡ�񷨶�����a��n��Ԫ�ؽ�������
template<class T>
void selectSort(T a[], int n) {
	for (i = 0; i < n - 1; i++) {
		int leastIndex = i;                 //��СԪ�ص��±��ֵ��Ϊ��
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[leastIndex])       //leastIndex ʼ�ռ�¼��ǰ�ҵ�����Сֵ���±�
				leastIndex = j;
		}
		mySwap(a[i], a[leastIndex]);        //����һ���ҵ�����СԪ���� a[i] ����
	}
}



#endif // !HEADER_9_12_H
