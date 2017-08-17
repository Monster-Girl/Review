//1.实现冒泡排序的和快速排序
#include<iostream>
using namespace std;
#include<assert.h>
void Print(int *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void BubbleSort(int *a, int size)   //时间复杂度：O(N^2)  稳定性
{
	assert(a);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i-1; j++)
		{
			if (a[j]>a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

void TestBubbleSort()
{
	int arr[] = { 3, 7, 5, 8, 9, 6, 1, 4, 2, 0 };
	BubbleSort(arr, 10);
	Print(arr, 10);
}


int PartSort(int *a, int left, int right)  //左右指针法
{          
	int key = a[right];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
			++begin;
		while (begin < end && a[end] >= key)
			--end;
		if (begin < end)
			swap(a[begin], a[end]);
	}
	swap(a[begin], a[right]);
	return begin;
}

void QuickSort(int *a, int left,int right)
{
	if (left >= right)
		return;
	int mid = PartSort(a, left, right);
	QuickSort(a, left, mid - 1);
	QuickSort(a, mid + 1, right);
}


void TestQuickSort()
{
	int arr[] = { 3, 7, 5, 8, 9, 6, 1, 4, 2, 0 };
	QuickSort(arr, 0, 9);
	Print(arr, 10);
}
//2.实现快速排序的非递归。
//并分析以下问题：
//1：什么时候快速排序最坏？怎么避免最坏情况的出现？
//2：快速排序的时间复杂度是多少？

int main()
{
	//TestBubbleSort();
	TestQuickSort();
	system("pause");
	return 0;
}