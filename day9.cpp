//1.实现一颗二叉树的层序遍历。
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
//2.给定一个整数N，那么N的阶乘N！末尾有多少个0呢？
//例如：N＝10，N！＝3 628 800，N！的末尾有两个0。
//思路：如果直接求，整数过大会导致溢出。
//N！=1×2×3×4×5×6×··· ×N
//N！=2^x ×3^y × 5^z ··········
//求0的个数，也就是求有多少2^x × 5^z的组合。
//因为能被2整除的数特别多，所以只需要考虑能整除5的个数。
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
