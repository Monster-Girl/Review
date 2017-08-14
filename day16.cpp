//1.由前序遍历和中序遍历重建二叉树（前序序列：1 2 3 4 5 6 - 中序序列:3 2 4 1 6 5）

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
//		TreeNode* root = new TreeNode(pre[0]);  //前序遍历第一个肯定是根结点
//
//		int rootpos = 0;
//		while (vin[rootpos] != pre[0])   //在中序遍历中找到根的位置
//		{
//			rootpos++;
//		}
//
//		//rootpos前都是左子树，后面的都是右子树
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

//2.C语言模式实现C++继承和多态。
//提示：C实现一个struct A和struct B各包含一个int成员a和b
//要求达到B继承了A的效果，也就是B里面包含一个A
//并且能达到多态的效果，
//也就是一个A*p指向A调的是A的函数，指向B调用的是B的函数。
 
#include<iostream>
using namespace std;

//C++实现继承和多态
//在C++的多态是通过虚函数virtual实现的
//virtual在内存中会建立一张虚函数表，然后当执行的时候，会通过相匹配的指针去访问
//继承是一种复用手段，
//在继承关系里基类的成员类的成员派生类的成员，由此达到复用的目的。
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

