//1.�������Ҷ�ӽڵ�ĸ���
//2.���������k��Ľڵ������
//3.һ����������һ�����ֵĴ��������������һ�룬�������ַ���
//�磺int a[] = { 2, 3, 2, 2, 2, 2, 2, 5, 4, 1, 2, 3 }���������һ���������2��
// 
//˼·һ�������������������һ����Χ�ڣ�����ֱ�ӽ���Ӧ�������ڸ�λ�á�
//��������һ��ĸ�����ֱ���жϾͺ�
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
//˼·�����ȶ�����������Ϊ�����������һ�룬��ͨ������λ���ķ����ɵ�
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