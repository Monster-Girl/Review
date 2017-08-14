//1.��ǰ���������������ؽ���������ǰ�����У�1 2 3 4 5 6 - ��������:3 2 4 1 6 5��

//* Definition for binary tree
//* struct TreeNode {
//*     int val;
//*     TreeNode *left;
//*     TreeNode *right;
//*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//* };

//class Solution {
//public:
//	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
//		int insize = vin.size();
//		if (insize == 0)
//			return NULL;
//		vector<int> preStart, preEnd;
//		vector<int> inStart, inEnd;
//		TreeNode* root = new TreeNode(pre[0]);  //ǰ�������һ���϶��Ǹ����
//
//		int rootpos = 0;
//		while (vin[rootpos] != pre[0])   //������������ҵ�����λ��
//		{
//			rootpos++;
//		}
//
//		//rootposǰ����������������Ķ���������
//		int i = 0;
//		for (; i<rootpos; i++)
//		{
//			preStart.push_back(pre[i + 1]);
//			inStart.push_back(vin[i]);
//		}
//
//		for (i = rootpos + 1; i<insize; i++)
//		{
//			preEnd.push_back(pre[i]);
//			inEnd.push_back(vin[i]);
//		}
//
//		root->left = reConstructBinaryTree(preStart, inStart);
//		root->right = reConstructBinaryTree(preEnd, inEnd);
//
//		return root;
//
//	}
//};

//2.C����ģʽʵ��C++�̳кͶ�̬��
//��ʾ��Cʵ��һ��struct A��struct B������һ��int��Աa��b
//Ҫ��ﵽB�̳���A��Ч����Ҳ����B�������һ��A
//�����ܴﵽ��̬��Ч����
//Ҳ����һ��A*pָ��A������A�ĺ�����ָ��B���õ���B�ĺ�����
 
#include<iostream>
using namespace std;

//C++ʵ�ּ̳кͶ�̬
//��C++�Ķ�̬��ͨ���麯��virtualʵ�ֵ�
//virtual���ڴ��лὨ��һ���麯����Ȼ��ִ�е�ʱ�򣬻�ͨ����ƥ���ָ��ȥ����
//�̳���һ�ָ����ֶΣ�
//�ڼ̳й�ϵ�����ĳ�Ա��ĳ�Ա������ĳ�Ա���ɴ˴ﵽ���õ�Ŀ�ġ�
class A
{
public:
	virtual void fun()
	{
		cout << "A_fun()" << endl;
	}

	A()
	{
		cout << "A()" << endl;
	}
	virtual ~A()
	{
		cout << "~A" << endl;
	}
};

class B :public A
{
public:
	void fun()
	{
		cout << "B_fun()" << endl;
	}
	
	B()
	{
		cout << "B()" << endl;
	}

	~B()
	{
		cout << "~B" << endl;
	}
};

void TestCpp()
{
	A* p = new A;
	p->fun();
	p->~A();
	A* pb = new B;
	pb->fun();
	pb->~A();
}

typedef void (*FUN)();
struct _a
{
	FUN _a_;
};

struct _b
{
	_a _ab;
};


void _fa()
{
	printf("_a_fun()\n");
}

void _fb()
{
	printf("_b_fun()\n");
}

void TestC()
{
	_a a;
	_b b;
	a._a_ = _fa;
	b._ab._a_ = _fb;

	_a *pa = &a;
	pa->_a_();
	_a *pb = (_a*)&b;
	pa->_a_();
}

int main()
{
	//TestCpp();
	TestC();
	system("pause");
	return 0;
}

