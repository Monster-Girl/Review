//1.使用两个栈实现一个队列
#include<iostream>
#include<stack>
using namespace std;

template<class T>
class Queue
{
public:
	void Push(T data)
	{
		s1.push(data);
	}

	void Pop()
	{
		if (s2.size() <= 0)
		{
			while (!s1.empty())
			{
				T tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
		}
		if (s2.size() == 0)
		{
			cout << "the queue is empty" << endl;
		}
		T data = s2.top();
		s2.pop();	
	}
	
private:
	stack<T> s1;
	stack<T> s2;
};

void TestQueue()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	
	q.Pop();
	q.Pop();
	q.Pop();
}

//2.使用两个队列实现一个栈
#include<queue>
template<class T>
class Stack
{
public:
	void Push(T data)
	{
		if (q1.empty() && q2.empty())
			q1.push(data);
		else if (q1.empty() && !q2.empty())
			q2.push(data);
		else
			q1.push(data);
	}

	void Pop()
	{
		if (q1.empty())
		{
			while (q2.size() != 1)
			{
				T tmp = q2.front();
				q2.pop();
				q1.push(tmp);
			}
			q2.pop();
		}
		else
		{
			while (q1.size() != 1)
			{
				T tmp = q1.front();
				q1.pop();
				q2.push(tmp);
			}
			q1.pop();
		}
	}

private:
	queue<T> q1;
	queue<T> q2;
};

void testStack()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();

}

//3.替换字符串中的空格为$$$。要求时间复杂度为O(N)
//例如：将"talk is cheap show me the code"替换为"talk$$$is$$$cheap$$$show$$$me$$$the$$$code"。
void ReplaceBlank(char str[],int length)
{
	int blank = 0;
	int newlen = 0;
	int i = 0;
	int oldlen = 0;
	while (str[i] != '\0')
	{
		++oldlen;
		if (isspace(str[i]))
			++blank;
		++i;
	}

	newlen = blank*2 + oldlen;  
	if (length < newlen)
		return;
	int newl = newlen;
	int oldl = oldlen;
	while (oldl >= 0 && newl > oldl)
	{
		if (isspace(str[oldl]))
		{
			str[newl--] = '$';
			str[newl--] = '$'; 
			str[newl--] = '$';
		}
		else
		{
			str[newl--] = str[oldl];
		}
		--oldl;
	}
}

void TestReplace()
{
	char str[50] = "talk is cheap show me the code" ;
	ReplaceBlank(str, 50);
	cout << str << endl;

}

int main()
{
	//TestQueue();
	//testStack();
	TestReplace();
	system("pause");
	return 0;
}