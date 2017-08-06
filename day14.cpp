//1.�ж�һ���ڵ��Ƿ���һ�ö������С���ע���⼸���ڵ㣬���Ƿ����ҵ���
//˼·���ж�һ������Ƿ��ڶ������У������ж�������ǲ����������
//1.�ǲ��Ƕ��������  ---�ǵĻ����ԣ���������͸������бȽϣ�Ȼ������ȥ����
#include<iostream>
using namespace std;
template<class K>
struct SearchNode
{
	K _key;
	SearchNode<K>* _left;
	SearchNode<K>* _right;
	SearchNode(const K& key)
		:_left(NULL)
		, _right(NULL)
		, _key(key)
	{}
};

template<class K>
class SearchTree
{
public:
	typedef SearchNode<K> Node;
	SearchTree()
		:_root(NULL)
	{}
	bool Insert(const K& key)
	{
		if (_root == NULL)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = NULL;
		Node* cur = _root;
		while (cur)  //�ж����Ǳ�
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		if (parent->_key >key)  //�ж���������
		{
			parent->_left = new Node(key);
			return true;
		}
		else
		{
			parent->_right = new Node(key);
			return true;
		}
	}

	Node* Find(const K& key)
	{
		if (_root == NULL)
			return NULL;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)
				return cur;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return NULL;
	}

	bool Remove(const K& key)
	{
		if (_root == NULL)
			return false;
		Node* cur = _root;
		Node* parent = NULL;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;

			}
			else
			{
				Node* del = cur;
				if (cur->_left==NULL)
				{
					if (parent == NULL)   //���ɾ���Ľ��ǡ���Ǹ��ڵ�
						_root = cur->_right;
					else
					{
						if (parent->_left == cur)  //�Ǹ��׵�����
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;
					}
				}  //ɾ���Ľ�㲻������ڵ㣬����Ҫ�����
				else if (cur->_right == NULL)
				{
					if (parent == NULL)   //���ɾ���Ľ��ǡ���Ǹ��ڵ�
						_root = cur->_left;
					else
					{
						if (parent->_left == cur)  //�Ǹ��׵�����
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}
				}  //ɾ���Ľ�㲻�����ҽ�㣬����Ҫ�����
				
				else  //�����ɾ��������������С�Ľ��
				{
					Node* subParent = cur;
					Node* subRight = cur->_right;
					while (subRight->_left)  //����������������
					{
						subParent = subRight;
						subRight = subRight->_left;
					}

					cur->_key = subRight->_key;
					del = subRight;

					if (subParent->_left == subRight)
						subParent->_left = subRight->_right;
					else
						subParent->_right = subRight->_right;

				}//��Ҫ���ǲ����

				delete del; 
				return true;
			}//�ҵ����
			return false;
		}//���ҽ��

	}
protected:
	Node* _root;
};

void TestSearch()
{
	SearchTree<int> s;
	int arr[] = { 5, 3, 4, 1, 7, 2, 6, 0, 10, 8, 11, 9};
	for (int i = 0; i < 12; i++)
	{
		s.Insert(arr[i]);
	}
	cout << s.Find(1)->_key << endl;
	cout << s.Find(2)->_key << endl;
	cout << s.Find(3)->_key << endl;
	cout << s.Find(4)->_key << endl;
	cout << s.Find(5)->_key << endl;
	cout << s.Find(7)->_key << endl;
	cout << s.Find(8)->_key << endl;

	s.Remove(7);
	cout << s.Find(7) << endl;
}

int main()
{
	TestSearch();
	system("pause");
	return 0;
}

//2.������Ƕ��������  ---�Ȳ������������ڲ���������
/*struct TreeNode
{
	T _data;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
}*/;

//Node* Find(const T& key)
//{
//	return _Find(_root, key);
//}
//
//Node* _Find(Node* root, const T& key)
//{
//	if (root == NULL)
//		return NULL;
//	if (root->_data == key)
//		return root;
//	Node* tmp = _Find(root->_left, key);
//	if (tmp)
//		return tmp;
//	return _Find(root->_right, key);
//}

//2.�ж�һ�Ŷ��������Ƿ�����һ����������������tree2��tree1��������
//˼·�����жϸ����ڸ���ȵ�����£�ȥ�ж�������λ�ú�ֵ����ͬ��λ��ֵ�������������
/**
* Definition of TreeNode:
* class TreeNode {
* public:
*     int val;
*     TreeNode *left, *right;
*     TreeNode(int val) {
*         this->val = val;
*         this->left = this->right = NULL;
*     }
* }
*/

//class Solution {
//public:
//	/*
//	* @param T1: The roots of binary tree T1.
//	* @param T2: The roots of binary tree T2.
//	* @return: True if T2 is a subtree of T1, or false.
//	*/
//
//	bool isSubtree(TreeNode * T1, TreeNode * T2) {
//		// write your code here
//		if (T2 == NULL) return true;
//		if (T1 == NULL) return false;
//		bool result = false;
//		if (T1->val == T2->val)
//			result = hasSubTree(T1, T2);
//		if (!result)
//			result = isSubtree(T1->left, T2);
//		if (!result)
//			result = isSubtree(T1->right, T2);
//
//		return result;
//	}
//
//	bool hasSubTree(TreeNode *t1, TreeNode *t2)
//	{
//		if ((t1 == NULL) && (t2 == NULL))
//			return true;
//		if ((t1 != NULL) && (t2 != NULL) && (t1->val == t2->val))
//			return hasSubTree(t1->left, t2->left) && hasSubTree(t1->right, t2->right);
//		return false;
//	}
//};