//1.Ԫ�س�ջ����ջ˳��ĺϷ��ԡ�
//�磺��ջ�����У�1, 2, 3, 4, 5������ջ����Ϊ��4, 5, 3, 2, 1������Ϸ���
//��ջ�����У�1, 2, 3, 4, 5������ջ����Ϊ��4, 5, 2, 3, 1�����򲻺Ϸ���
//˼·������һ������ջ���������ͬ����ջ�������ͬ����������ջָ������ƶ�
//����ջָ���Ѿ�ָ����󣬳�ջ����û�У��Ͳ��ǺϷ���
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
//2.����һ������������λ��1�ĸ�����Ҫ��Ч�ʾ����ܵĸߡ�
//������ȷ�������͸����Ķ�������1�ĸ�����
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