//�ж������Ƿ�������������󻷵ĳ��ȣ��������󻷵���ڵ㣿����������ÿ�������ʱ�临�Ӷȣ�
#include<iostream>
using namespace std;
#include<assert.h>
typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	ListNode* _next;
}Node;

Node* BuyNode(DataType data)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->_data = data;
	cur->_next = NULL;
	return cur;
}

void Print(Node* head)
{
	if (head == NULL)
		return;
	Node* cur = head;
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->_next;
	}
	cout << endl;
}

void Push(Node*& head, DataType data)
{
	if (head == NULL)
	{
		head = BuyNode(data);
		return;
	}
	Node* cur = head;
	while(cur->_next)
		cur = cur->_next;
	cur->_next= BuyNode(data);
}

Node* Find(Node* head, DataType data)
{
	if (head == NULL)
		return NULL;
	Node* cur = head;
	while (cur)
	{
		if (cur->_data == data)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}

Node* IsCircle(Node* head)  //�ж������Ƿ������
{
	if (head == NULL)
		return NULL;
	Node* fast = head;
	Node* slow = head;
	while (fast && fast->_next)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if (fast == slow)
			return slow;
	}
	return NULL;
}

size_t CircleLen(Node* head)  //�������󻷵ĳ��ȣ�
{
	Node* meet = IsCircle(head);
	Node* cur = meet->_next;
	size_t len = 1;
	while(cur != meet)
	{
		cur = cur->_next;
		++len;
	}
	return len;
}

Node* CircleEnter(Node* head) //�������󻷵���ڵ㣿
{
	Node* meet = IsCircle(head);
	Node* cur = head;
	assert(meet && head);
	while (cur && meet)
	{
		if (meet == cur)
			return cur;
		cur = cur->_next;
		meet = meet->_next;
	}
	return NULL;
}

int main()
{
	Node* head = NULL;
	Push(head, 1);
	Push(head, 2);
	Push(head, 3);
	Push(head, 4);
	Push(head, 5);
	Push(head, 6);
	Push(head, 7);
	Push(head, 8);
	Push(head, 9);
	Node* ret = Find(head, 5);
	Node* re = Find(head, 9);
	re->_next = ret;
	Node* cir = IsCircle(head);
	if (cir != NULL)
		cout << "��" << endl;
	else
		cout << "���ǻ�" << endl;
	cout << "���ĳ��ȣ�" << CircleLen(head) << endl;
	cout << "�������" << CircleEnter(head)->_data << endl;
	system("pause");
}