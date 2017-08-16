//1.实现选择排序和堆排序
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

void SelectSort(int *a, int size)   //无论什么情况，时间复杂度都为O(N^2)
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

void HeapSort(int *a, int size)   //时间复杂度为：O(N*logN)
{
	assert(a);
	for (int i = (size - 2) / 2; i >= 0; i--)  //调整成一个堆
		adjustdown(a, size, i);
	
	int end = size - 1;
	while (end > 0)   //取最大的交换
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

//2.本公司现在要给公司员工发波福利，在员工工作时间会提供大量的水果供员工补充营养。
//由于水果种类比较多，但是却又不知道哪种水果比较受欢迎，然后公司就让每个员工报告了自己最爱吃的k种水果，
//并且告知已经将所有员工喜欢吃的水果存储于一个数组中。
//然后让我们统计出所有水果出现的次数，并且求出大家最喜欢吃的前k种水果。
//
//要求打印出最喜欢的水果，并且效率尽可能的高。
//提示：尽量STL的容器和算法，这样能更快速高效的实现
//

//思路：首先这是一个topK的问题，可以考虑用优先级队列
//priority_queue:
//第一个参数填优先级队列要放啥，
//第二个填优先级队列用什么构成，
//第三个参数一般是默认的，大堆/小堆（包括怎么比较）


void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	map<string, int> count;
	for (size_t i = 0; i < fruits.size(); i++)  //把水果对应的存入map中
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
	//西瓜 4  香蕉3  苹果3 橘子2
	vector<string> fruits = { "西瓜", "香蕉","西瓜", "香蕉", "苹果", "西瓜", "苹果", "橘子", "西瓜", "香蕉" };
	GetFavoriteFruit(fruits, 2);
}

int main()
{
	//TestSort();
	TestTopK();
	system("pause");
	return 0;
}