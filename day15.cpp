//1.判断一棵树是否是完全二叉树。提示：层序遍历变型题。
//思路：对一个二叉树进行层序遍历，如果某个结点左右结点只存在一个
//就不是完全二叉树，如果左右结点都不存在则当前结点满足。
//bool JudgeCompleteBinaryTree()
//{
//	if (_root == NULL)
//		return false;
//	queue<Node*> q;
//	q.push(_root);
//	while (!q.empty())
//	{
//		Node* tmp = q.front();
//		q.pop();
//		if (tmp->_left == NULL && tmp->_right == NULL)
//			return true;
//		if (tmp->_left != NULL && tmp->_right != NULL)
//		{
//			q.push(tmp->_left);
//			q.push(tmp->_right);
//		}
//		else
//			return false;
//	}
//}


//2.求二叉树中两个节点的最近公共祖先。
//要求考虑以下三种种情况，给出解决方案，并解决：
//1：二叉树每个节点有parent（三叉链）
//2：二叉树是搜索二叉树。
//3：就是普通二叉树。（尽可能实现时间复杂度为O（N））

//思路：如果是情况1可以将这两个结点的路径分别存在两个链表里，然后求两个链表的相交结点。
//如果是一棵二叉搜索树，如果两个结点分布在某个根结点左右，这个根结点既是所求的结点
//否则，就查找最大结点在哪边
//如果是普通的二叉树，可以通过栈去保存查找这两个结点的路径
//当size一样大时，可以利用出栈的比较来判断最近的公共祖先

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
//	/**
//	* @param root: The root of the binary search tree.
//	* @param A and B: two nodes in a Binary.
//	* @return: Return the least common ancestor(LCA) of the two nodes.
//	*/
//	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
//		// write your code here
//		if (root == NULL | root == A || root == B)  return root;
//		TreeNode *left = lowestCommonAncestor(root->left, A, B);
//		TreeNode *right = lowestCommonAncestor(root->right, A, B);
//		if (left && right)  return root;
//		if (left)  return left;
//		if (right) return right;
//	}
//};