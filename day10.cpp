//1.求二叉树叶子节点的个数
//2.求二叉树第k层的节点个数。
//3.一个数组中有一个数字的次数超过了数组的一半，求出这个字符。
//如：int a[] = { 2, 3, 2, 2, 2, 2, 2, 5, 4, 1, 2, 3 }，求出超过一半的数字是2。
// 
//思路一：数组的数是整数且在一定范围内，可以直接将对应次数加在该位置。
//超过数组一半的个数，直接判断就好
#include<iostream>
using namespace std;
#define SIZE 100
bool inval = false;
bool CheckArr(int *arr, int length)
{
	if (arr == NULL || length < 0)
		inval = true;
	return inval;
}

bool CheckHalf(int *arr, int length,int half)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == half)
			count++;
	}

	bool checkhalf = true;
	if (count * 2 < length)
	{
		inval = true;
		checkhalf = false;
	}
	return checkhalf;
}

int HalfThanSize(int *arr, int length)
{
	if (CheckArr(arr, length))
		return -1;
	int i = 0;
	int result = 0;
	int num[SIZE] = { 0 };
	for (; i < length; i++)
	{
		num[arr[i]]++;
	}

	int size = length / 2;
	for (i = 0; i < length; i++)
	{
		if (num[i]>size)
			result = i;
	}
	if (!CheckHalf(arr, length, i))
		return -2;
	return result;
}
//思路二：先对数组排序，因为有这个数超过一半，在通过找中位数的方法可得
int HalfThanSize2(int *arr, int length)
{
	if (CheckArr(arr, length))
		return -1;

}


void TestHalfNum()
{
	int arr[] = { 2, 3, 2, 2, 2, 2, 2, 5, 4, 1, 2, 3 };
	cout << HalfThanSize(arr, sizeof(arr)/sizeof(arr[0])) << endl;
}


int main()
{
	TestHalfNum();
	system("pause");
	return 0;
}