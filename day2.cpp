//1.逆置/反转单链表
//#include<iostream>
//using namespace std;
//#include<assert.h>
//typedef int DataType;
//typedef struct ListNode
//{ 
//	DataType _data;
//	ListNode* _next;
//}Node;
//
//Node* BuyNode(DataType data)
//{
//	Node* head = (Node*)malloc(sizeof(Node));
//	assert(head);
//	head->_next = NULL;
//	head->_data = data;
//	return head;
//}
//
//void Print(Node* head)
//{
//	if (head == NULL)
//		return;
//	Node* cur = head;
//	while (cur)
//	{
//		cout << cur->_data << " ";
//		cur = cur->_next;
//	}
//	cout << endl;
//}
//
//void PushBack(Node*& head, DataType data)
//{
//	if (head == NULL)
//	{
//		head = BuyNode(data);
//		return;
//	}
//	Node* cur = head;
//	while (cur->_next)
//	{
//		cur = cur->_next;
//	}
//	cur->_next = BuyNode(data);
//}
//
//void Reverse(Node*& head)
//{
//	assert(head);
//	if (head->_next == NULL)
//		return;
//	Node* newHead = NULL;
//	Node* cur = head;
//	Node* tmp = head;
//	while(cur)
//	{
//		tmp = cur;
//		cur = cur->_next;
//		tmp->_next = newHead;
//		newHead=tmp;
//	}
//	head = newHead;
//}

//int main()
//{
//	Node* head=NULL;
//	PushBack(head, 1);
//	PushBack(head, 2);
//	PushBack(head, 3);
//	PushBack(head, 4);
//	PushBack(head, 5);
//	Print(head);
//	Reverse(head);
//	Print(head);
//	system("pause");
//	return 0;
//}

//2.查找单链表的倒数第k个节点，要求只能遍历一次链表
//Node* FindLastK(Node* head, int k)
//{
//	if (head == NULL)
//		return NULL;
//	Node* fast = head;
//	Node* slow = head;
//	while (k--)
//	{
//		if (fast->_next==NULL)
//			return NULL;
//		fast = fast->_next;
//	}
//	while (fast)
//	{
//		fast = fast->_next;
//		slow = slow->_next;
//	}
//	return slow;
//}
//
//int main()
//{
//	Node* head = NULL;
//	PushBack(head, 1);
//	PushBack(head, 2);
//	PushBack(head, 3);
//	PushBack(head, 4);
//	PushBack(head, 5);
//	Print(head);
//	Node* ret = FindLastK(head, 8);
//	if (ret == NULL)
//		cout << "no exist" << endl;
//	else
//		cout << ret->_data << endl;
//	Node* ret2 = FindLastK(head, 4);
//	if (ret2 == NULL)
//		cout << "no exist" << endl;
//	else
//		cout << ret2->_data << endl;
//
//	system("pause");
//	return 0;
//}

//3.实现一个Add函数，让两个数相加，但是不能使用+、-、*、/等四则运算符。ps:也不能用++、--等等
//思路：在我们进行+的运算时，其实是正常相加然后在加上有进位的部分。
//&：当某位数字都为1时，这时候我们就要进位——左移一位
//^：正常的相加
#include<iostream>
using namespace std;
int Add(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	int carry = a & b;  //用来统计进位问题
	if(carry!=0)
		carry <<= 1;
	int sum = a ^ b;  //正常的运算
	return Add(sum,carry);
}
int main()
{
	cout << Add(1, 0) << endl;
	cout << Add(1, 1) << endl;
	cout << Add(1, 2) << endl; 
	cout << Add(1, 3) << endl; 
	cout << Add(1, 4) << endl;
	cout << Add(1, 5) << endl;
	cout << Add(1, 6) << endl;
	cout << Add(1, 7) << endl;
	cout << Add(1, 8) << endl; 
	cout << Add(1, 9) << endl;
	cout << Add(1, 10) << endl;
	system("pause");
	return 0;
}
