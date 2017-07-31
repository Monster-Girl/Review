//1.将二叉搜索树转换成一个排序的双向链表。
//提示：要求不能创建任何新的结点，只能调整树中结点指针的指向，也就是left当prev，right当next。
//中序线索化的变型。

//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};*/
//class Solution {
//public:
//	TreeNode* Convert(TreeNode* pRootOfTree)
//	{
//		TreeNode *pLastInList = NULL;
//		ConvertNode(pRootOfTree, pLastInList);
//
//		TreeNode *head = pLastInList;
//		while (head != NULL && head->left != NULL)   //找头结点
//			head = head->left;
//		return head;
//	}
//
//	void ConvertNode(TreeNode* pNode, TreeNode*& pLastInList)
//	{
//		if (pNode == NULL)
//			return;
//		TreeNode *cur = pNode;
//		if (cur->left != NULL)  //查找最小的结点
//			ConvertNode(pNode->left, pLastInList);
//		cur->left = pLastInList;
//		if (pLastInList != NULL)     //找右子树
//			pLastInList->right = cur;
//
//		pLastInList = cur;
//		if (pLastInList->right != NULL)
//			ConvertNode(cur->right, pLastInList);
//	}
//};


//2. C++实现一个线程安全且高效单例类。
//尽量能考虑懒汉模式和饿汉模式，并分析它们的优缺点。  
#include<iostream>
using namespace std;
#include<mutex>
#include<windows.h>
//单例模式：1.保证全局只有一个唯一实例对象
//          2.提供获取这个唯一实例的接口
//要实现一个单例模式，那就必须将构造函数设为私有函数
//定义一个静态实例，当需要的时候，再去创建该实例
class Singleton  //不考虑线程安全的单例模式
{
public:
	static Singleton* GetInstance()
	{
		if (_inst == NULL)
		{
			_inst = new Singleton;
		}
		return _inst;
	}

	void Print()
	{
		cout << "Singleton" << endl;
	}

private:
	Singleton()
		:_a(0)
	{}
	
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

	int _a;
	
	static Singleton* _inst;
};

Singleton* Singleton::_inst = NULL;

void TestSingleton()
{
	Singleton::GetInstance()->Print();
	Singleton::GetInstance()->Print();
	Singleton::GetInstance()->Print();

	//Singleton copy(*Singleton::GetInstance());   //拷贝构造会使这个单例出现多次，所以必须设置成防拷贝
}

//考虑线程安全的两种实现是采用加锁
//第一种：懒汉模式
//只有当你需要的时候才进行创建，
class Singleton_Lazy
{
public:
	static Singleton_Lazy* GetInstance()
	{
		if (_inst == NULL)
		{
			lock_guard<mutex> lock(_lock);  //lock_guard是一种自解锁
			if (_inst == NULL)
			{
				Singleton_Lazy *tmp = new Singleton_Lazy;

				//双检查带来的问题，顺序存在问题
				//因为可能在程序中会先new空间，然后进行赋值，此时是随机值，在进行构造函数
				//本来的顺序是：先new，在构造，最后赋值

				MemoryBarrier();  //加内存栅栏，可以保证程序按序执行
				_inst = tmp;
			}
		}
		return _inst;
	}

	void DelInstance()
	{
		lock_guard<mutex> lock(_lock);
		if (_inst)
		{
			delete _inst;
			_inst = NULL;
		}
	}

private:
	Singleton_Lazy()
		:_a(0)
	{}

	//防拷贝
	Singleton_Lazy(const Singleton_Lazy&);
	Singleton_Lazy& operator=(const Singleton_Lazy&);

	~Singleton_Lazy()
	{}

	int _a;

	static Singleton_Lazy* _inst;  //在类里定义，在外面初始化
	static mutex _lock;
};

Singleton_Lazy* Singleton_Lazy::_inst = NULL;



//懒汉和饿汉的区别：
//懒汉相对复杂，但是各种情景下都适用
//饿汉虽然简洁，但是适应性会收到限制，比如动态库