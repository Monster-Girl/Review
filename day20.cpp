//1.ʵ��ð������ĺͿ�������
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
void BubbleSort(int *a, int size)   //ʱ�临�Ӷȣ�O(N^2)  �ȶ���
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


int PartSort(int *a, int left, int right)  //����ָ�뷨
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
//2.ʵ�ֿ�������ķǵݹ顣
//�������������⣺
//1��ʲôʱ��������������ô���������ĳ��֣�
//2�����������ʱ�临�Ӷ��Ƕ��٣�

int main()
{
	//TestBubbleSort();
	TestQuickSort();
	system("pause");
	return 0;
}