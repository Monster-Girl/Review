//1.ʵ��ð������ĺͿ�������
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


//�����������ʱ�򣬿��ŵ���������ʱ����Բ�������ȡ�з�
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


//��һ����Ϊ��׼��Ȼ���ұ�����ĺ�С�ģ�Ȼ�󽻻���ֱ��������ָ������
//���м���Ǹ������н������������Ϊ�磬��ߵĶ�С���ұߵĶ���
int PartSort1(int *a, int left, int right)  //����ָ�뷨
{      
	//�Ż�������ȡ�з�
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

//�����һ����Ϊ��׼���������׼������key��
//�����Ҵ���key�ģ��ҵ��˾ͺ�end����
//Ȼ�������С��key�ģ��ҵ��˾ͽ���
//���ѱ�key��/С�Ķ������˺��ʵ�λ����
int PartSort2(int *a, int begin, int end)   //�ڿӷ�
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


//����ָ��ȥ��С�ģ���ָ���Ҵ�ģ�Ȼ���ҵ��ͽ���
//
int PartSort3(int *a, int begin, int end)  //ǰ��ָ�뷨
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
//2.ʵ�ֿ�������ķǵݹ顣
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

//1��ʲôʱ��������������ô���������ĳ��֣�
//��һ�����������ʱ�򣬿��ŵ�������
//���⣺���Բ�������ȡ�з�
//2�����������ʱ�临�Ӷ��Ƕ��٣�
//ʱ�临�Ӷ�Ϊ��O(N^2)

int main()
{
	//TestBubbleSort();
	//TestQuickSort();
	TestQuickSortNonR();
	system("pause");
	return 0;
}