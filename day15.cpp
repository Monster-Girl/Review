//1.�ж�һ�����Ƿ�����ȫ����������ʾ��������������⡣
//˼·����һ�����������в�����������ĳ��������ҽ��ֻ����һ��
//�Ͳ�����ȫ��������������ҽ�㶼��������ǰ������㡣
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


//2.��������������ڵ������������ȡ�
//Ҫ���������������������������������������
//1��������ÿ���ڵ���parent����������
//2����������������������
//3��������ͨ����������������ʵ��ʱ�临�Ӷ�ΪO��N����

//˼·����������1���Խ�����������·���ֱ�������������Ȼ��������������ཻ��㡣
//�����һ�ö���������������������ֲ���ĳ����������ң����������������Ľ��
//���򣬾Ͳ�����������ı�
//�������ͨ�Ķ�����������ͨ��ջȥ�����������������·��
//��sizeһ����ʱ���������ó�ջ�ıȽ����ж�����Ĺ�������

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