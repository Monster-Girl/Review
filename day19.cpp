//1.ʵ��ѡ������Ͷ�����
#include<iostream>
using namespace std;
#include<assert.h>
#include<vector>
#include<queue>
#include<string>
#include<map>
void Print(int *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void SelectSort(int *a, int size)   //����ʲô�����ʱ�临�Ӷȶ�ΪO(N^2)
{
	assert(a);
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int minIndex = left;
		int maxIndex = right;
		for (int i = left; i <= right; i++)
		{
			if (a[i] < a[minIndex])
				minIndex = i;
			if (a[i]>a[maxIndex])
				maxIndex = i;
		}
		
		swap(a[left], a[minIndex]);
		if (maxIndex == left)
			maxIndex = minIndex;
		swap(a[right], a[maxIndex]);
		++left;
		--right;
	}
}

void adjustdown(int *a, int size, int root)
{
	assert(a);
	int child = root * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] < a[child + 1])
			++child;
		if (a[child]>a[root])
		{
			swap(a[child], a[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int *a, int size)   //ʱ�临�Ӷ�Ϊ��O(N*logN)
{
	assert(a);
	for (int i = (size - 2) / 2; i >= 0; i--)  //������һ����
		adjustdown(a, size, i);
	
	int end = size - 1;
	while (end > 0)   //ȡ���Ľ���
	{
		swap(a[0], a[end]);
		adjustdown(a, end, 0);
		end--;
	}
}

void TestSort()
{
	int arr[] = { 5, 6, 7, 3, 4, 2, 9, 8, 1, 0 };
	//SelectSort(arr,10);
	HeapSort(arr, 10);
	Print(arr, 10);
}

//2.����˾����Ҫ����˾Ա��������������Ա������ʱ����ṩ������ˮ����Ա������Ӫ����
//����ˮ������Ƚ϶࣬����ȴ�ֲ�֪������ˮ���Ƚ��ܻ�ӭ��Ȼ��˾����ÿ��Ա���������Լ���Ե�k��ˮ����
//���Ҹ�֪�Ѿ�������Ա��ϲ���Ե�ˮ���洢��һ�������С�
//Ȼ��������ͳ�Ƴ�����ˮ�����ֵĴ�����������������ϲ���Ե�ǰk��ˮ����
//
//Ҫ���ӡ����ϲ����ˮ��������Ч�ʾ����ܵĸߡ�
//��ʾ������STL���������㷨�������ܸ����ٸ�Ч��ʵ��
//

//˼·����������һ��topK�����⣬���Կ��������ȼ�����
//priority_queue:
//��һ�����������ȼ�����Ҫ��ɶ��
//�ڶ��������ȼ�������ʲô���ɣ�
//����������һ����Ĭ�ϵģ����/С�ѣ�������ô�Ƚϣ�


void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	map<string, int> count;
	for (size_t i = 0; i < fruits.size(); i++)  //��ˮ����Ӧ�Ĵ���map��
	{
		map<string, int>::iterator it = count.find(fruits[i]);
		if (it != count.end())
			it->second++;
		else
		{
			count.insert(make_pair(fruits[i], 1));
		}
	}
	

	struct Compare
	{
		bool operator()(map<string, int>::iterator l, map<string, int>::iterator r)
		{
			return l->second < r->second;
		}
	};

	priority_queue<map<string, int>::iterator,vector<map<string,int>::iterator>,Compare> p;
	map<string, int>::iterator countIt = count.begin();
	while (countIt != count.end())
	{
		p.push(countIt);
		++countIt;	
	}

	while (k--)
	{
		p.top()->first;
		cout << p.top()->first << ":" << p.top()->second << endl;
		p.pop();
	}
}

void TestTopK()
{
	//���� 4  �㽶3  ƻ��3 ����2
	vector<string> fruits = { "����", "�㽶","����", "�㽶", "ƻ��", "����", "ƻ��", "����", "����", "�㽶" };
	GetFavoriteFruit(fruits, 2);
}

int main()
{
	//TestSort();
	TestTopK();
	system("pause");
	return 0;
}