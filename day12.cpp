//1.�ж�һ�ö������Ƿ���ƽ�������
//2.��һ�Ŷ������ľ���
//˼·���ݹ�ȥ�жϣ���ÿ���������н���
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
//3.һ��m*n�ľ��󣬴����Ҵ��ϵ��¶��ǵ�����.
//��һ����x���ж�x�Ƿ��ھ����С�Ҫ��Ч�ʾ����ܵĸߡ�
//#include<iostream>
//using namespace std;
//bool Find(int* arr, int col, int row, int key)
//{
//	bool flag = false;
//	if (arr != NULL && col > 0 && row > 0)
//	{
//		int i = 0;  //�� col
//		int j = row - 1; //�� row
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