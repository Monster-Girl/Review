//1.实现归并排序。
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

//2.有一个大文件内容如下：
//data.txt
//小明，1班，88分
//小李，1班，90分
//小王，1班，99分
//小杨，1班，59分
//要求：这个文件内容很大，不能全部放到内存，请按第三列的分数对这个文件的内容进行排序。
//ps：可以考虑两方面入手：归并排序或linux指令。
//另外如果用代码实现，可以尽可能使考虑使用STL辅助，
//也不用造太大的文件，太麻烦，就给一个小文件，给10行数据，假设内存中最多能放3行数据，这样模拟实现就可以。



//思路：将所有信息保存在一个结构体中，然后通过归并去排序
//如果数据还是比较大，可以先建小堆，然后通过比较，得到一个有序的，在进行归并。

//在Linux下，可以用sort去排序，数据以某个字符隔开，然后去获取信息，然后在比较
//struct info
//{
//	string _name;
//	string _class;
//	int _score;
//};

int main()
{
	TestMergeSort();
	system("pause");
	return 0;
}