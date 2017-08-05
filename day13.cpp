//1.ʵ�ֶ�������ǰ�� / ���� / ����ǵݹ������
#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>
template<class T>
struct TreeNode
{
	T _data;
	TreeNode<T>* _left;
	TreeNode<T>* _right;

	TreeNode(const T& x)
		:_data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class T>
class BinaryTree
{
	typedef TreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}

	BinaryTree(const BinaryTree<T>& t);
	BinaryTree<T>& operator=(const BinaryTree<T>& t);

	BinaryTree(T* a, size_t n, const T& invalid = T())
	{
		size_t index = 0;
		_root = _createTree(a, n, invalid, index);
	}

	void PrevOrderNonR()
	{
	if (_root == NULL)
		return;
	Node* cur = _root;
	stack<Node*> s;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cout << cur->_data << " ";
			cur = cur->_left;
		}
		Node* tmp = s.top();
		s.pop();
		cur = tmp->_right;
	}
	cout << endl;
}

void InOrderNonR()
{
	if (_root == NULL)
		return;
	Node* cur = _root;
	stack<Node*> s;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->_left;
		}
		Node* tmp = s.top();
		cout << tmp->_data << " ";
		s.pop();
		cur = tmp->_right;
	}
	cout << endl;
}

void PostOrderNonR()
{
	if (_root == NULL)
		return;
	Node* cur = _root;
	Node* prev = _root;
	stack<Node*> s;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			prev = cur;
			cur = cur->_left;
		}
		Node* tmp = s.top();
		if (tmp->_right == NULL || tmp->_right == prev)
		{
			cout << tmp->_data << " ";
			prev = tmp;
			s.pop();
		}
		else
			cur = tmp->_right;
	}
	cout << endl;
}

void PrevOrder()
{
	_PrevOrder(_root);
	cout << endl;
}

void InOrder()
{
	_InOrder(_root);
	cout << endl;
}

void PostOrder()
{
	_PostOrder(_root);
	cout << endl;
}
protected:
	Node* _createTree(T *a, size_t n, const T& invalid, size_t& index)
	{
		Node* root = NULL;
		if (a[index] != invalid && index < n)
		{
			root = new Node(a[index]);
			root->_left = _createTree(a, n, invalid, ++index);
			root->_right = _createTree(a, n, invalid, ++index);
		}
		return root;
	}

	void _PrevOrder(Node* root)
	{
		if (root == NULL)
			return;
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}

	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}
	protected:
		Node* _root;
};

void TestOrder()
{
	int arr[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	BinaryTree<int> b1(arr, 15, '#');
	cout << "PrevOrder:";
	b1.PrevOrder();
	cout << "PrevOrderNonR:";
	b1.PrevOrderNonR();

	cout << "InOrder:";
	b1.InOrder();
	cout << "InOrderNonR:";
	b1.InOrderNonR();

	cout << "PostOrder:";
	b1.PostOrder();
	cout << "PostOrderNonR:";
	b1.PostOrderNonR();
}



//2.��֪����A��B��Ԫ�طֱ��ò���ͷ���ĵ�����洢��
//����difference()������⼯��A��B�Ĳ��������������ڼ���A�ĵ������С�
//���磬������A = { 5, 10, 20, 15, 25, 30 }��
//����B = { 5, 15, 35, 25 }��
//��ɼ����A = { 10, 20, 30 }��
//
//������Ľṹ���Ͷ������£�
//
//struct node
//{
//	int elem;
//	node* next;
//};
//����ɺ���void difference(node** LA, node* LB)��
struct node
{
	int elem;
	node* next;
};

node* buyNode(int data)
{
	node* cur = (node*)malloc(sizeof(node));
	cur->elem = data;
	cur->next = NULL;
	return cur;
}

void Push(node*& head,int data)
{
	if (head == NULL)
	{
		head = buyNode(data);
		return;
	}
	node* cur = head;
	while (cur->next)
		cur = cur->next;
	cur->next= buyNode(data);
}

void Print(node* l1)
{
	if (l1 == NULL)
		return;
	while (l1)
	{
		cout << l1->elem << " ";
		l1 = l1->next;
	}
	cout << endl;
}

void difference(node** LA, node* LB)
{
	node* pa = *LA;
	node *pre = NULL;
	node *q = NULL;
	while(pa)
	{
		node *pb = LB;
		while (pb && pb->elem != pa->elem)
			pb = pb->next;
		if(pb)  //�ҵ�����ͬ��Ԫ��
		{
			if (!pre)  //���ͷ�ĵ�һ�������ͬ����ôֱ������ȥ
				*LA = pa->next;
			else  //��ͷ���������
				pre->next= pa->next;  //���浱ǰ������һ��ָ��
			
			q = pa;  //ɾ���ظ����
			pa = pa->next;
			free(q);
		}
		else   //�Ѿ�������
		{
			pre = pa;
			pa = pa->next;
		}
	}
}

void testnode()
{
	node* l1=NULL;
	node* l2=NULL;
	Push(l1, 5);
	Push(l1, 10);
	Push(l1, 20);
	Push(l1, 25);
	Push(l1, 30);
	Push(l2, 5);
	Push(l2, 15);
	Push(l2, 35);
	Push(l2, 25);
	difference(&l1, l2);
	Print(l1);
}

int main()
{
	//TestOrder();
	testnode();
	system("pause");
	return 0;
}

