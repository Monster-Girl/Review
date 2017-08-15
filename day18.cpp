//1.ʵ�ֲ��������ϣ������
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

//��������  
//3 2 4 1
//2 3 4 1
//1 2 3 4
void InsertSort(int *a, int len)   //ʱ�临�Ӷȣ�O(N^2)
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

//�ȶ�����������з�������Ȼ��������������Խ��Խ����
//�����������Ʋ�������
//ϣ���������ǶԲ��������һ���Ż����������������ʱ��
//������ͨ������������������������
void ShellSort(int *a, int len)
{
	assert(a);
	int gap = len;
	while (gap > 1)
	{
		gap = gap / 3 + 1;  //��֤���һ��һ���ǲ�������
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