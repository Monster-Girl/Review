//1.������������ת����һ�������˫������
//��ʾ��Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��Ҳ����left��prev��right��next��
//�����������ı��͡�

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
//		while (head != NULL && head->left != NULL)   //��ͷ���
//			head = head->left;
//		return head;
//	}
//
//	void ConvertNode(TreeNode* pNode, TreeNode*& pLastInList)
//	{
//		if (pNode == NULL)
//			return;
//		TreeNode *cur = pNode;
//		if (cur->left != NULL)  //������С�Ľ��
//			ConvertNode(pNode->left, pLastInList);
//		cur->left = pLastInList;
//		if (pLastInList != NULL)     //��������
//			pLastInList->right = cur;
//
//		pLastInList = cur;
//		if (pLastInList->right != NULL)
//			ConvertNode(cur->right, pLastInList);
//	}
//};


//2. C++ʵ��һ���̰߳�ȫ�Ҹ�Ч�����ࡣ
//�����ܿ�������ģʽ�Ͷ���ģʽ�����������ǵ���ȱ�㡣  
#include<iostream>
using namespace std;
#include<mutex>
#include<windows.h>
//����ģʽ��1.��֤ȫ��ֻ��һ��Ψһʵ������
//          2.�ṩ��ȡ���Ψһʵ���Ľӿ�
//Ҫʵ��һ������ģʽ���Ǿͱ��뽫���캯����Ϊ˽�к���
//����һ����̬ʵ��������Ҫ��ʱ����ȥ������ʵ��
class Singleton  //�������̰߳�ȫ�ĵ���ģʽ
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

	//Singleton copy(*Singleton::GetInstance());   //���������ʹ����������ֶ�Σ����Ա������óɷ�����
}

//�����̰߳�ȫ������ʵ���ǲ��ü���
//��һ�֣�����ģʽ
//ֻ�е�����Ҫ��ʱ��Ž��д�����
class Singleton_Lazy
{
public:
	static Singleton_Lazy* GetInstance()
	{
		if (_inst == NULL)
		{
			lock_guard<mutex> lock(_lock);  //lock_guard��һ���Խ���
			if (_inst == NULL)
			{
				Singleton_Lazy *tmp = new Singleton_Lazy;

				//˫�����������⣬˳���������
				//��Ϊ�����ڳ����л���new�ռ䣬Ȼ����и�ֵ����ʱ�����ֵ���ڽ��й��캯��
				//������˳���ǣ���new���ڹ��죬���ֵ

				MemoryBarrier();  //���ڴ�դ�������Ա�֤������ִ��
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

	//������
	Singleton_Lazy(const Singleton_Lazy&);
	Singleton_Lazy& operator=(const Singleton_Lazy&);

	~Singleton_Lazy()
	{}

	int _a;

	static Singleton_Lazy* _inst;  //�����ﶨ�壬�������ʼ��
	static mutex _lock;
};

Singleton_Lazy* Singleton_Lazy::_inst = NULL;



//�����Ͷ���������
//������Ը��ӣ����Ǹ����龰�¶�����
//������Ȼ��࣬������Ӧ�Ի��յ����ƣ����綯̬��