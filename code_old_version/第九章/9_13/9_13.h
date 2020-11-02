#ifndef HEADER_9_13_H
#define HEADER_9_13_H

//辅助函数:交换x, y的值
template<class T>
void mySwap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

//用起泡法对数组a的n个元素进行排序
template<class T>
void bubbleSort(T a[], int n) {
	int i = n - 1;                               //i是下一趟需参与排序交换的元素的最大下标
	while (i > 0) {                              //继续排序过程，直到最后一趟排序没有交换发生，或已达 n-1 趟
		lastExchangeIndex = 0;                   //每一趟开始时，设置交换标志为0 (未交换)
		for (int j = 0; j < i; j++) {            //每一趟对元素 a[0] ..a[i] 进行比较和交换
			if (a[j] > a[j + 1]) {               //如果元素 a[j+1]<a[j], 交换之
				mySwap(a[j], a[j + 1]);
				lastExchangeIndex = j;           //记录被交换的一对元素中较小的下标
			}
		}
		i = lastExchangeIndex;                   //将i设置为本趟被交换的最后一对元素中较小的下标
	}
}
#endif // !HEADER_9_13_H
