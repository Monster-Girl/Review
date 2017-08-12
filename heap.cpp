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


	Heap(T* a, size_t n)  //堆化数组
	{
		_a.reserve(n);
		for (size_t i = 0; i < n; i++)  //将所有的结点push进去
		{
			_a.push_back(a[i]);
		}

		//可以把所有的叶子结点看成是 一个合法的堆
		//所以需要从最后一个结点的父节点开始向下调整
		//child=parent*2+1;
		for (int i = (_a.size() - 2 / 2); i >= 0; i--) 
		{                                            
			_AdjustDown(i);
		}
	}

	void push(const T& x)  //时间复杂度为log(N)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}
	
	void pop()          //删除的时间复杂度为log(N)
	{
		assert(_a.empty);
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);   //删除后需要堆化，将堆重新调整
	}

	
protected:
	

	void _AdjustDown(int root)
	{
		int parent = root;
		int child = parent * 2 + 1;
		while (child < _a.size())
		{
			if (child + 1 < _a.size() && _a[child + 1] > _a[child])  //在左右孩子中找最小的
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
		if (child+1<n && a[child + 1]>a[child])   //child+1 防止越界
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