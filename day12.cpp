//1.判断一棵二叉树是否是平衡二叉树
//2.求一颗二叉树的镜像
//思路：递归去判断，对每个子树进行交换
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
//class Solution {
//public:
//	void Mirror(TreeNode *pRoot) {
//		if (pRoot == NULL)
//			return;
//		if ((pRoot->left == NULL) && (pRoot->right == NULL))
//			return;
//		TreeNode* tmp = pRoot->left;
//		pRoot->left = pRoot->right;
//		pRoot->right = tmp;
//
//		if (pRoot->left)
//			Mirror(pRoot->left);
//		if (pRoot->right)
//			Mirror(pRoot->right);
//	}
//};
//3.一个m*n的矩阵，从左到右从上到下都是递增的.
//给一个数x，判断x是否在矩阵中。要求效率尽可能的高。
//#include<iostream>
//using namespace std;
//bool Find(int* arr, int col, int row, int key)
//{
//	bool flag = false;
//	if (arr != NULL && col > 0 && row > 0)
//	{
//		int i = 0;  //列 col
//		int j = row - 1; //行 row
//		while (i < col && j >= 0)
//		{
//			if (arr[i*col+j] == key)
//			{
//				flag = true;
//				break;
//			}
//			else if (arr[i*col + j] > key)
//				j--;
//			else
//				i++;
//		}
//	}
//	return flag;
//}
//
//int main()
//{
//	int arr[4][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
//	cout << Find(*arr, 4, 3, 10) << endl;
//	system("pause");
//	return 0;
//}