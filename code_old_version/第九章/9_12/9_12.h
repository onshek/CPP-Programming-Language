#ifndef HEADER_9_12_H
#define HEADER_9_12_H

//辅助函数:交换x,y的值
template<class T>
void mySwap(T& x, T& y) {
	temp = x;
	x = y;
	y = temp;
}

//用选择法对数组a的n个元素进行排序
template<class T>
void selectSort(T a[], int n) {
	for (i = 0; i < n - 1; i++) {
		int leastIndex = i;                 //最小元素的下标初值设为工
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[leastIndex])       //leastIndex 始终记录当前找到的最小值的下标
				leastIndex = j;
		}
		mySwap(a[i], a[leastIndex]);        //将这一趟找到的最小元素与 a[i] 交换
	}
}



#endif // !HEADER_9_12_H
