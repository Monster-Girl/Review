//1.��������ĸ߶�
//2.����һ�Ŷ�����-->Destroy(Node* root)
//#include<iostream>
//using namespace std;
//#include<assert.h>
//template<class T>
//struct TreeNode
//{
//	T _data;
//	TreeNode<T>* _left;
//	TreeNode<T>* _right;
//
//	TreeNode(const T& x)
//		:_data(x)
//		, _left(NULL)
//		, _right(NULL)
//	{}
//};
//
//template<class T>
//class BinaryTree
//{
//	typedef TreeNode<T> Node;
//public:
//	BinaryTree()
//		:_root(NULL)
//	{}
//
//	BinaryTree(const BinaryTree<T>& t);
//	BinaryTree<T>& operator=(const BinaryTree<T>& t);
//
//	BinaryTree(T* a, size_t n, const T& invalid = T())
//	{
//		size_t index = 0;
//		_root = _createTree(a, n, invalid, index);
//	}
//
//	~BinaryTree()
//	{
//		_Destory(_root);
//	}
//
//	void PrevOrder()
//	{
//		_PrevOrder(_root);
//		cout << endl;
//	}
//
//	size_t GetDepth()
//	{
//		return _GetDepth(_root);
//	}
//
//	void Destory()
//	{
//		_Destory(_root);
//		_root = NULL;
//	}
//protected:
//	Node* _createTree(T *a, size_t n, const T& invalid, size_t& index)
//	{
//		Node* root = NULL;
//		if (a[index] != invalid && index < n)
//		{
//			root = new Node(a[index]);
//			root->_left = _createTree(a, n, invalid, ++index);
//			root->_right = _createTree(a, n, invalid, ++index);
//		}
//		return root;
//	}
//
//	void _PrevOrder(Node* root)
//	{
//		if (root == NULL)
//			return;
//		cout << root->_data << " ";
//		_PrevOrder(root->_left);
//		_PrevOrder(root->_right);
//	}
//
//	size_t _GetDepth(Node* root)
//	{
//		if (root == NULL)
//			return 0;
//		size_t left = _GetDepth(root->_left);
//		size_t right = _GetDepth(root->_right);
//
//		if (left > right)
//			return left + 1;
//		else
//			return right + 1;
//	}
//
//	void _Destory(Node* root)
//	{
//		if (root == NULL)
//			return;
//		_Destroy(root->_left);
//		_Destroy(root->_right);
//		delete root;
//	}
//protected:
//	Node* _root;
//};
//
//void TestTree()
//{
//	int arr[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
//	BinaryTree<int> b2(arr, 15, '#');
//	b2.PrevOrder();
//	cout << "GetDepth:" << b2.GetDepth() << endl;
//	b2.Destory();
//	b2.PrevOrder();
//}
//

//3.����ת������һ�������һ����k��
//��������1��2��3��4��5��6��k = 2����ת��2��1��4��3��6��5��
//��k = 3, ��ת��3��2��1��6��5��4��
//��k = 4����ת��4��3��2��1��5��6��
//�ó���ʵ��Node* RotateList(Node* list, size_t k).
//��ʾ����������������õ��������͡�


#include<iostream>
using namespace std;
#include<assert.h>
typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	ListNode* _next;
}Node;


Node* BuyNode(DataType data)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->_data = data;
	cur->_next = NULL;
	return cur;
}

void PushBack(Node*& head, DataType data)
{
	if (head == NULL)
	{
		head = BuyNode(data);
		return;
	}
	Node* cur = head;
	while(cur->_next)
		cur = cur->_next;
	cur ->_next = BuyNode(data);
}

size_t Size(Node* head)
{
	if (head == NULL)
		return 0;
	Node* cur = head;
	size_t count = 0;
	while (cur)
	{
		++count;
		cur = cur->_next;
	}
	return count;
}

//˼·����KΪһ��������ã�Ȼ����еݹ�
//ÿ�α��淭ת�����һ�����ָ�����һ��
//������Щ���ȫ��������
Node* RotateList(Node* head, size_t k)  
{
	if (k <= 1)
		return head;
	if (head == NULL || head->_next == NULL)
		return head;
	size_t size = Size(head);
	size_t pos = k;
	Node* newHead = NULL;
	Node* next = NULL;  //��������һ�����õ����һ��������һ��ָ��
	Node* prev = NULL;
	Node* cur = head;  //
	if (size < k)
		return head;
	while (pos >= 1)   //��һ�����������
	{
		next = cur->_next;
		pos--;
		if (pos == 0)
			newHead = cur;
		cur->_next = prev;
		prev = cur;
		cur = next;
	}
	Node* last = newHead;
	while (last->_next != NULL) //�ҵ����һ����㣬��������
		last = last->_next;
	Node* nextHead = RotateList(next, k);  //����һ��K�������������
	last->_next = nextHead;
	return newHead;
}

void Print(Node* head)
{
	if (head == NULL)
		return;
	Node* cur = head;
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->_next;
	}
	cout << endl;
}

void TestList()
{
	ListNode* l1=NULL;
	PushBack(l1, 1);
	PushBack(l1, 2);
	PushBack(l1, 3);
	PushBack(l1, 4);
	PushBack(l1, 5);
	PushBack(l1, 6);
	Print(l1);
	cout << "Size:" << Size(l1) << endl;
	Node* ret = RotateList(l1, 3);
	Print(ret);
}

int main()
{
	//TestTree();
	TestList();
	system("pause");
	return 0;
}