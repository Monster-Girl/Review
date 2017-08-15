//1.实现插入排序和希尔排序
#include<iostream>
using namespace std;
#include<assert.h>

void Print(int *a, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序  
//3 2 4 1
//2 3 4 1
//1 2 3 4
void InsertSort(int *a, int len)   //时间复杂度：O(N^2)
{
	assert(a);
	for (int i = 0; i < len-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
	Print(a, len);
}

//先对整个数组进行分组排序，然后整个区间慢慢越来越有序
//最后的排序类似插入排序
//希尔排序算是对插入排序的一种优化，当数据量过大的时候
//可以先通过分组排序，最后整体插入排序
void ShellSort(int *a, int len)
{
	assert(a);
	int gap = len;
	while (gap > 1)
	{
		gap = gap / 3 + 1;  //保证最后一次一定是插入排序
		for (int i = 0; i < len - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end]>tmp)
				{
					a[end + gap] = a[end];
					end-=gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
	Print(a, len);
}

void TestSort()
{
	int arr[10] = { 5, 2, 4, 3, 8, 7, 6, 9, 0, 1 };
	//InsertSort(arr, 10);
	ShellSort(arr, 10);
}

int main()
{
	TestSort();
	system("pause");
	return 0;
}