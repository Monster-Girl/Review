//1.ʵ��һ��ջStack��Ҫ��ʵ��Push����ջ����Pop����ջ����Min��������Сֵ�Ĳ�������ʱ�临�Ӷ�ΪO(1)
#include<iostream>
using namespace std;
#include<stack>
#include<assert.h>
template<class T>
class  Stack
{
public:
	void Push(T data)
	{
		_data.push(data);
		if (_min.size() == 0 || _min.top() >= data)
			_min.push(data);
		_min.push(_min.top());   //����ռλ
	}
	void Pop()
	{
		if (_data.size() < 0 || _min.size() < 0)
			return;
		_data.pop();
		_min.pop();
	}
	T& Min()
	{
		assert(_data.size() > 0 && _min.size() > 0);
		return _min.top();
	}

private:
	stack<T> _data;
	stack<T> _min;
};

void TestStack()
{
	Stack<int> s;
	s.Push(4);
	s.Push(3);
	s.Push(2);
	s.Push(2);
	s.Push(5);

	s.Pop();
	s.Pop();

	cout<<s.Min()<< endl;
}
//2.����һ���ַ����е�һ��ֻ�������ε��ַ���
//���磺��abcdefabcdefabc���е�һ��ֻ��������Ϊ��d��.
//Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)

char Search(char *str)
{
	char Buf[256] = { 0 };
	char* p = str;
	for (int i = 0; i < strlen(str); i++)
	{
		Buf[str[i]]++;
	}
	p = str;
	while (*p != '\0')
	{
		if (Buf[*p] == 2)
		return (*p);
		p++;
	}
	return NULL;
}

void TestSearch()
{
	char *arr1 = "yxyabecabre";
	cout << arr1 << endl;
	cout << Search(arr1) << endl;
	char *arr2 = "abcdefabcdefabc";
	cout << arr2 << endl;
	cout << Search(arr2) << endl;
}

int main()
{
	//TestStack();
	TestSearch();
	system("pause");
	return 0;
}