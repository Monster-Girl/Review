//1.�������Ҷ�ӽڵ�ĸ���
#include<iostream>
using namespace std;
template<class T>
struct TreeNode
{
	T _data; 
	TreeNode<T>* _left;
	TreeNode<T>* _right;
};

template<class T>
class BinaryTree
{
	typedef TreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}

	~BinaryTree()
	{}
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
protected:
	Node* _root;
};
//2.���������k��Ľڵ������
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


int main()
{
	TestHalfNum();
	system("pause");
	return 0;
}