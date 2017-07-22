//1.元素出栈、入栈顺序的合法性。
//如：入栈的序列（1, 2, 3, 4, 5），出栈序列为（4, 5, 3, 2, 1），则合法。
//入栈的序列（1, 2, 3, 4, 5），出栈序列为（4, 5, 2, 3, 1），则不合法。
//思路：借用一个辅助栈，如果不相同就入栈，如果相同，弹出，出栈指针向后移动
//当入栈指针已经指向最后，出栈序列没有，就不是合法的
#include<iostream>
using namespace std;
#include<stack>

bool IsLegal(const int* Push, const int* Pop, int length)
{
	if (Push == NULL || Pop == NULL || length < 0)
		return false;
	const int* nextPush = Push;
	const int* nextPop = Pop;
	stack<int> s;
	while(nextPop - Pop < length)
	{
		while (s.empty() || s.top() != *nextPop)
		{
			if (nextPush - Push == length)
				break;
			s.push(*nextPush);
			nextPush++;
		}
		if (s.top() != *nextPop)
			break;
		s.pop();
		nextPop++;
	}
	if (s.empty() && nextPop - Pop == length)
		return true;
	return false;
}

void TestIslegal()
{
	int push[] = { 1, 2, 3,4, 5 };
	int pop[] = { 4, 5, 2, 3, 1 };
	cout << IsLegal(push, pop, 5) << endl;
}
//2.计算一个整数二进制位中1的个数。要求效率尽可能的高。
//且能正确求正数和负数的二进制中1的个数。
int NumOf1(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1)&n;
	}
	return count;
}

void TestNum()
{
	cout << NumOf1(-1) << endl;
	cout << NumOf1(10) << endl;
}

int main()
{
	//TestIslegal();
	TestNum();
	system("pause");
	return 0;
}