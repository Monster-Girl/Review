#include<iostream>
using namespace std;
#include<assert.h>
#include<vector>
template<class T>
class Heap
{
public:
	Heap()
	{}


	Heap(T* a, size_t n)  //�ѻ�����
	{
		_a.reserve(n);
		for (size_t i = 0; i < n; i++)  //�����еĽ��push��ȥ
		{
			_a.push_back(a[i]);
		}

		//���԰����е�Ҷ�ӽ�㿴���� һ���Ϸ��Ķ�
		//������Ҫ�����һ�����ĸ��ڵ㿪ʼ���µ���
		//child=parent*2+1;
		for (int i = (_a.size() - 2 / 2); i >= 0; i--) 
		{                                            
			_AdjustDown(i);
		}
	}

	void push(const T& x)  //ʱ�临�Ӷ�Ϊlog(N)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}
	
	void pop()          //ɾ����ʱ�临�Ӷ�Ϊlog(N)
	{
		assert(_a.empty);
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);   //ɾ������Ҫ�ѻ����������µ���
	}

	
protected:
	

	void _AdjustDown(int root)
	{
		int parent = root;
		int child = parent * 2 + 1;
		while (child < _a.size())
		{
			if (child + 1 < _a.size() && _a[child + 1] > _a[child])  //�����Һ���������С��
				++child;
			if (_a[child]>_a[parent])
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}


	void _AdjustUp(int child)
	{
		int parent = (child - 1) >> 1;
		while (child > 0)
		{
			if (_a[child] > _a[parent])
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
				break;
		}
	}
protected:
	vector<T> _a;
};

void AdjustDown(int* a, size_t n, size_t parent)
{
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1<n && a[child + 1]>a[child])   //child+1 ��ֹԽ��
			child++;
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, size_t n)
{
	assert(a);
	for (int i = (n - 2) / 2; i>= 0; i--)
		AdjustDown(a, n, i);

	int end = n - 1;
	while (end>0)
	{
		swap(a[0], a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}


int main()
{
	int a[] = { 10,11,13,12,16,18,15,17,14,19 };
	Heap<int> h(a, 10);
	HeapSort(a, 10);
	system("pause");
	return 0;
}