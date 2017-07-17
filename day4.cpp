//1.判断两个链表是否相交，若相交，求交点。（假设链表不带环)
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

Node* IsCircle(Node* l)
{
	if (l == NULL)
		return NULL;
	Node* fast = l;
	Node* slow = l;
	while (fast && fast->_next)
	{
		
		fast = fast->_next->_next;
		slow = slow->_next;
		if (fast == slow)
			return slow;
	}
	return NULL;
}

Node* EnterNode(Node* l)
{
	Node* meet = IsCircle(l);
	if (meet == NULL)
		return NULL;
	Node* cur = l;
	assert(cur&&meet);
	while (cur && meet)
	{
		if (cur == meet)
			return meet;
		cur = cur->_next;
		meet = meet->_next;
	}
	return NULL;
}

void test1()
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
}

void testCir()
{
	Node* l3 = NULL;
	PushBack(l3, 1);
	PushBack(l3, 2);
	PushBack(l3, 3);
	PushBack(l3, 4);
	PushBack(l3, 5);
	PushBack(l3, 6);
	Node* cir = Find(l3, 3);
	Node* tail = Find(l3, 6);
	tail->_next = cir;
	Node* iscir = IsCircle(l3);
	if (iscir != NULL)
		cout << "is cir" << endl;
	else
		cout << "not cir" << endl;
	cout << (EnterNode(l3))->_data << endl;
}
//2.判断两个链表是否相交，若相交，求交点。（假设链表可能带环）
//先判断链表是否带环，如果不带环就有1来处理。
//如果带环，需要考虑这个交点在环内还是环外。
//如果在环外，那么可以求出环的入口点，继续利用链表的长度差来查找。
//如果在环内，可以先求出环的入口处，把两个链表拆开看，同样利用长度差来查找。
size_t len(Node* head, Node* tail)
{
	assert(head && tail);
	size_t len = 0;
	while (head)
	{
		
		if (head == tail)
			return len;
		++len;
		head = head->_next;
		
	}
	return len;
}
size_t Cirlen(Node* head)
{
	Node* meet = EnterNode(head);
	if (meet == NULL)
		return 0;
	Node* cur = meet->_next;
	size_t len = 1;
	while (cur)
	{
		if (cur == meet)
			return len;
		++len;
		cur=cur->_next;
	}
	return len;
}

Node* UnionNodeCir(Node* l1, Node* l2)
{
	Node* iscir = IsCircle(l1);
	if (iscir == NULL) //先处理不带环的
	{
		return UnionMeet(l1, l2);
	}
	Node* meet1 = EnterNode(l1);
	Node* meet2 = EnterNode(l2);
	size_t len1 = len (l1, meet1)+Cirlen(l1);
	size_t len2 = len (l2, meet2)+Cirlen(l2)-len(meet1,meet2);

	Node* cur1 = l1;
	Node* cur2 = l2;
	if (len1 > len2)
	{
		size_t tmp = len1 - len2;
		while (tmp--)
			cur1 = cur1->_next;
	}
	else
	{
		size_t tmp = len2 - len1;
		while (tmp--)
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

void testUnionR()  //环外
{
	Node* l1 = NULL;
	Node* l2 = NULL;
	PushBack(l1, 1);
	PushBack(l1, 2);
	PushBack(l1, 3);
	PushBack(l1, 4);   //链表的交点
	PushBack(l1, 5);  //环的入口点
	PushBack(l1, 6);
	PushBack(l1, 7);
	PushBack(l1, 8);
	PushBack(l2, 9);
	PushBack(l2, 10);
	Node* ret = Find(l1, 5);
	Node* ret2 = Find(l1, 8);  //带环链表
	ret2->_next = ret;

	Node* tail = Find(l2, 10);  //交集链表
	Node* meet = Find(l1, 4);
	tail->_next = meet;

	cout << (UnionNodeCir(l1, l2))->_data << endl;
}

void testUnion()
{
	Node* l1 = NULL;
	Node* l2 = NULL;
	PushBack(l1, 1);
	PushBack(l1, 2);
	PushBack(l1, 3);
	PushBack(l1, 4);  
	PushBack(l1, 5);  //环的入口点
	PushBack(l1, 6);
	PushBack(l1, 7); //链表的交点
	PushBack(l1, 8);
	PushBack(l2, 9);
	PushBack(l2, 10);
	Node* ret = Find(l1, 5);
	Node* ret2 = Find(l1, 8);  //带环链表
	ret2->_next = ret;

	Node* tail = Find(l2, 10);  //交集链表
	Node* meet = Find(l1, 7);
	tail->_next = meet;

	cout << (UnionNodeCir(l1, l2))->_data << endl;

}

int main()
{
	//test1();
	//testCir();
	testUnionR();
	//testUnion();
	system("pause");
	return 0;
}



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

//一共会打印6个。
//当i=0时，fork出两个进程，打印两遍“-”；
//当i=1时，当前有4个进程，所以又打印了四遍“-”
//所以共6个。


