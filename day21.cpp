//1. µœ÷πÈ≤¢≈≈–Ú°£

#include<iostream>
using namespace std;
#include<assert.h>
void Print(int *a, int size)
{
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

void _Merge(int *src,int *dst, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin)/2;

	_Merge(src, dst, begin, mid);
	_Merge(src, dst, mid + 1, end);

	
	int b1 = begin;
	int b2 = mid + 1;
	int index = begin;

	while (b1 <= mid  && b2 <= end)
	{
		if (src[b1] < src[b2])
			dst[index++] = src[b1++];
		else
			dst[index++] = src[b2++];
	}

	while (b1 <= mid)
		dst[index++] = src[b1++];
	while (b2 <= end)
		dst[index++] = src[b2++];

	int i = begin;
	while (i < index)
	{
		src[i] = dst[i];
		i++;
	}
}
void MergeSort(int *a, int size)
{
	assert(a);
	int *tmp = new int[size];
	_Merge(a, tmp, 0, size - 1);
	delete[] tmp;
}

void TestMergeSort()
{
	int a[] = { 5, 4, 3, 2, 1 };
	MergeSort(a, 5);
	Print(a, 5);
}

int main()
{
	TestMergeSort();
	system("pause");
	return 0;
}