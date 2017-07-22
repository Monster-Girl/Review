//1.ʵ��һ�Ŷ������Ĳ��������
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
//	/**
//	* @param root: The root of binary tree.
//	* @return: Level order a list of lists of integer
//	*/
//public:
//	vector<vector<int>> levelOrder(TreeNode *root) {
//		// write your code here
//		vector<vector<int>> res;
//		if (root == NULL)
//			return res;
//
//		queue<TreeNode*> q;
//		q.push(root);
//
//		while (!q.empty())
//		{
//			vector<int> level;
//			int size = q.size();
//			for (int i = 0; i<size; i++)
//			{
//				TreeNode *node = q.front();
//				q.pop();
//				level.push_back(node->val);
//
//				if (node->left)
//					q.push(node->left);
//				if (node->right)
//					q.push(node->right);
//			}
//			res.push_back(level);
//		}
//		return res;
//	}
//};
//
//2.����һ������N����ôN�Ľ׳�N��ĩβ�ж��ٸ�0�أ�
//���磺N��10��N����3 628 800��N����ĩβ������0��
//˼·�����ֱ������������ᵼ�������
//N��=1��2��3��4��5��6�������� ��N
//N��=2^x ��3^y �� 5^z ��������������������
//��0�ĸ�����Ҳ�������ж���2^x �� 5^z����ϡ�
//��Ϊ�ܱ�2���������ر�࣬����ֻ��Ҫ����������5�ĸ�����
#include<iostream>
using namespace std;
int countZeroNum(int n)
{
	int num = 0;
	for (int i = 0; i <= n; i++)
	{
		int j = i;
		while (j % 5 == 0 && j!=0)
		{
			num++;
			j /= 5;
		}
	}
	return num;
}

void testNum()
{
	cout << countZeroNum(10) << endl;
}

int main()
{
	testNum();
	system("pause");
	return 0;
}
