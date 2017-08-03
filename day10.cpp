//1.�������Ҷ�ӽڵ�ĸ���
//2.���������k��Ľڵ������

#include<iostream>
using namespace std;
#include<assert.h>
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

	~BinaryTree()
	{
		_Destory(_root);
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}

	size_t GetLeafSize()
	{
		return _GetLeafSize(_root);
	}

	size_t GetKLeafSize(size_t k)
	{
		assert(k > 0);
		return _GetKLeafSize(_root, k);
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
	
	size_t _GetLeafSize(Node* root)
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL && root->_right == NULL)
			return 1;
		return _GetLeafSize(root->_left) + _GetLeafSize(root->_right);
	}

	size_t _GetKLeafSize(Node* root, size_t k)
	{
		if (root == NULL)
			return 0;
		if (k == 1)
			return 1;
		return _GetKLeafSize(root->_left, k - 1) + _GetKLeafSize(root->_right, k - 1);
		//������k-1��������k--����,�ڵݹ��ʱ��ʹ��k--������һ��
	}

	void _Destory(Node* root)
	{
		if (root == NULL)
			return;
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}
protected:
	Node* _root;
};

void TestTree()
{
	int arr[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	BinaryTree<int> b1(arr, 15, '#');
	b1.PrevOrder();
	cout << "GetLeafSize:" << b1.GetLeafSize() << endl;
	cout << "GetKLeafSize:"<<b1.GetKLeafSize(5) << endl;
	cout << "GetKLeafSize:" << b1.GetKLeafSize(4) << endl;
	cout << "GetKLeafSize:" << b1.GetKLeafSize(3) << endl;
	cout << "GetKLeafSize:" << b1.GetKLeafSize(2) << endl;
	cout << "GetKLeafSize:" << b1.GetKLeafSize(1) << endl;
}

int main()
{
	TestTree();
	system("pause");
	return 0;
}
//3.һ����������һ�����ֵĴ��������������һ�룬�������ַ���
//�磺int a[] = { 2, 3, 2, 2, 2, 2, 2, 5, 4, 1, 2, 3 }���������һ���������2��
// 
//˼·һ�������������������һ����Χ�ڣ�����ֱ�ӽ���Ӧ�������ڸ�λ�á�
//��������һ��ĸ�����ֱ���жϾͺ�
//#include<iostream>
//using namespace std;
//#define SIZE 100
//bool inval = false;
//bool CheckArr(int *arr, int length)
//{
//	if (arr == NULL || length < 0)
//		inval = true;
//	return inval;
//}
//
//bool CheckHalf(int *arr, int length,int half)
//{
//	int count = 0;
//	for (int i = 0; i < length; i++)
//	{
//		if (arr[i] == half)
//			count++;
//	}
//
//	bool checkhalf = true;
//	if (count * 2 < length)
//	{
//		inval = true;
//		checkhalf = false;
//	}
//	return checkhalf;
//}
//
//int HalfThanSize(int *arr, int length)
//{
//	if (CheckArr(arr, length))
//		return -1;
//	int i = 0;
//	int result = 0;
//	int num[SIZE] = { 0 };
//	for (; i < length; i++)
//	{
//		num[arr[i]]++;
//	}
//
//	int size = length / 2;
//	for (i = 0; i < length; i++)
//	{
//		if (num[i]>size)
//			result = i;
//	}
//
//	if (!CheckHalf(arr, length, result))
//		return -2;
//	return result;
//}
////˼·�����ȶ�����������Ϊ�����������һ�룬��ͨ������λ���ķ����ɵ�
//int HalfThanSize2(int *arr, int length)
//{
//	if (CheckArr(arr, length))
//		return -1;
//	int result = arr[0];
//	int time = 1;
//	for (int i = 1; i < length; ++i)
//	{
//		if (time == 0)
//		{
//			result = arr[i];
//			time = 1;
//		}
//		else if (result == arr[i])
//			time++;
//		else
//			time--;
//	}
//	
//	if (!CheckHalf(arr, length, result))
//		return -2;
//	return result;
//}
//
//
//void TestHalfNum()
//{
//	int arr[] = { 2, 3, 2, 2, 2, 2, 2, 5, 4, 1, 2, 3 };
//	cout <<"HalfThanSize:"<< HalfThanSize(arr, sizeof(arr)/sizeof(arr[0])) << endl;
//	cout <<"HalfThanSize2:"<< HalfThanSize2(arr, sizeof(arr) / sizeof(arr[0])) << endl;
//}

//int main()
//{
//	TestHalfNum();
//	system("pause");
//	return 0;
//}