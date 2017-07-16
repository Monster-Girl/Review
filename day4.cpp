//1.判断两个链表是否相交，若相交，求交点。（假设链表不带环)
#include<iostream>
using namespace std;
typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	ListNode* _next;
}Node;

Node* BuyNode(DataType data)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->_next = NULL;
	cur->_data = data;
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
void PushBack(Node*& head, DataType data)
{
	if (head == NULL)
	{
		head = BuyNode(data);
		return;
	}
	Node* cur = head;
	while (cur->_next)
	{
		cur = cur->_next;
	}
	cur->_next = BuyNode(data);
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

bool IsUnion(Node* l1, Node* l2)
{
	if (l1 == NULL || l2 == NULL)
		return false;
	Node* cur1 = l1;
	Node* cur2 = l2;
	while (cur1)
		cur1 = cur1->_next;
	while (cur2)
		cur2 = cur2->_next;
	if (cur1 == cur2)
		return true;
	return false;
}

Node* UnionMeet(Node* l1, Node* l2)
{
	bool ret=IsUnion(l1, l2);
	if (ret == false)
		return NULL;
	size_t len1 = 0;
	size_t len2 = 0;
	Node* cur1 = l1;
	Node* cur2 = l2;
	while (cur1)
	{
		++len1;
		cur1 = cur1->_next;
	}
	while (cur2)
	{
		++len2;
		cur2 = cur2->_next;
	}
	cur1 = l1;
	cur2 = l2;
	if (len1 > len2)
	{
		size_t i = len1 - len2;
		while (i--)
			cur1 = cur1->_next;
	}
	else
	{
		size_t i = len2 - len1;
		while (i--)
			cur2 = cur2->_next;

	}

	while (cur1 && cur2)
	{
		if (cur1 == cur2)
			return cur1;
		cur1 = cur1->_next;
		cur2 = cur2->_next;
	}
	return NULL;
}

int main()
{
	Node* l1 = NULL;
	Node* l2 = NULL;
	PushBack(l1, 1);
	PushBack(l1, 2);
	PushBack(l1, 3);
	PushBack(l1, 4);
	PushBack(l1, 5);
	PushBack(l2, 6);
	PushBack(l2, 7);
	Node* ret = Find(l1, 4);
	Node* ret2 = Find(l2, 7);
	ret2->_next = ret;
	Print(l1);
	Print(l2);
	cout << IsUnion(l1, l2) << endl;
	cout << (UnionMeet(l1, l2))->_data << endl;
	system("pause");
	return 0;


}
//2.判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】

//3.请问下面的程序一共输出多少个“ - ”？
//int main(void)
//{
//	int i;
//	for (i = 0; i<2; i++){
//		fork();
//		printf("-");
//	}
//
//	return 0;
//}

