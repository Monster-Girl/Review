//1.实现冒泡排序的和快速排序
#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>
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


//当数组有序的时候，快排的情况最差，这个时候可以采用三数取中法
int getMid(int *a, int left, int right)
{
	int mid = left + (right - left) >> 2;
	if (a[left] < a[mid])   //left  mid
	{
		if (a[mid] < a[right])   //left  mid  right
			return mid;
		else if (a[left]>a[right])   //right  left  mid  
			return left;
		else
			return right;
	}
	else   //mid left
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}

}


//以一个数为基准，然后找比它大的和小的，然后交换，直到这两个指针相遇
//和中间的那个数进行交换，以这个数为界，左边的都小，右边的都大
int PartSort1(int *a, int left, int right)  //左右指针法
{      
	//优化：三数取中法
	int mid = getMid(a, left, right);
	swap(a[mid], a[right]);

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

//以最后一个数为基准，将这个基准保存在key中
//从左找大于key的，找到了就和end交换
//然后从右找小于key的，找到了就交换
//最后把比key大/小的都放在了合适的位置上
int PartSort2(int *a, int begin, int end)   //挖坑法
{
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
			++begin;
		a[end] = a[begin];
		while (begin < end && a[end] >= key)
			--end;
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}


//用慢指针去找小的，快指针找大的，然后找到就交换
//
int PartSort3(int *a, int begin, int end)  //前后指针法
{
	int prev = begin - 1;
	int cur = begin;
	while (cur < end)
	{
		if (a[cur] >= a[end])
			cur++;
		if (cur != prev && a[cur] < a[end])
		{
			prev++;
			swap(a[cur], a[prev]);
			cur++;
		}
	}
	swap(a[++prev], a[end]);
	return prev;
}

void QuickSort(int *a, int left,int right)
{
	assert(a);
	if (left >= right)
		return;
	int mid = PartSort3(a, left, right);
	QuickSort(a, left, mid - 1);
	QuickSort(a, mid + 1, right);
}


void TestQuickSort()
{
	int arr1[] = { 3, 7, 5, 8, 9, 6, 1, 4, 2, 0 };
	int arr[] = { 3,5,2,4,1};
	QuickSort(arr, 0, 4);
	Print(arr, 10);
}
//2.实现快速排序的非递归。
void QuickSortNonR(int *a, int left, int right)
{
	stack<int> s;
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		int begin = s.top();
 		s.pop();
        int end = s.top();
		s.pop();

		int mid = PartSort3(a, begin,end);
		if (begin < mid - 1)
		{
			s.push(mid - 1);
			s.push(begin);
		}
		if (mid + 1 < right)
		{
			s.push(end);
			s.push(mid + 1);
		}
	}
}

void TestQuickSortNonR()
{
	int arr[] = { 3, 5, 2, };
	QuickSortNonR(arr, 0, 2);
}

//1：什么时候快速排序最坏？怎么避免最坏情况的出现？
//当一个数组有序的时候，快排的情况最坏。
//避免：可以采用三数取中法
//2：快速排序的时间复杂度是多少？
//时间复杂度为：O(N^2)

int main()
{
	//TestBubbleSort();
	//TestQuickSort();
	TestQuickSortNonR();
	system("pause");
	return 0;
}