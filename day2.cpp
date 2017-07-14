//1.����/��ת������
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

//2.���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
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

//3.ʵ��һ��Add����������������ӣ����ǲ���ʹ��+��-��*��/�������������ps:Ҳ������++��--�ȵ�
//˼·�������ǽ���+������ʱ����ʵ���������Ȼ���ڼ����н�λ�Ĳ��֡�
//&����ĳλ���ֶ�Ϊ1ʱ����ʱ�����Ǿ�Ҫ��λ��������һλ
//^�����������
#include<iostream>
using namespace std;
int Add(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	int carry = a & b;  //����ͳ�ƽ�λ����
	if(carry!=0)
		carry <<= 1;
	int sum = a ^ b;  //����������
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
