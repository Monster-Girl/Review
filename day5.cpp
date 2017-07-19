//1.删除一个无头单链表的非尾节点
#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>
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


void Delete(Node*& head, DataType data)
{
	if (head == NULL)
		return;
	Node* del = Find(head,data);
	if (del == NULL)
		return;
	Node* next = del->_next;
	Node* cur = next->_next;
	del->_data = next->_data;
	del->_next = cur;
	delete next;
}

void testDel()
{
	Node* head = NULL;
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	PushBack(head, 5);
	PushBack(head, 6);
	PushBack(head, 7);
	Node* cur = Find(head, 3);
	Delete(cur, 4);
	Print(head);
}

//2.从尾到头打印单链表
void TailToHead(Node* head)
{
	stack<int> s1;
	if (head == NULL)
		return;
	while(head!=NULL)
	{
		s1.push(head->_data);
		head = head->_next;
	}
	
	while (!s1.empty())
	{
		int data = s1.top();
		cout << data << " ";
		s1.pop();
	}
	cout << endl;
}

void TailToHeadR(Node* head)
{
	if (head == NULL)
		return;
	if (head != NULL)
	{
		TailToHeadR(head->_next);
	}
	cout << head->_data << " ";	
}

void testPrint()
{
	Node* head = NULL;
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	PushBack(head, 5);
	PushBack(head, 6);
	PushBack(head, 7);
	//TailToHead(head);
	TailToHeadR(head);
	cout << endl;
}


int main()
{
	//testDel
	testPrint();
	system("pause");
	return 0;
}

//3.复杂链表的复制。
//一个链表的每个节点，有一个指向next指针指向下一个节点，还有一个random指针指向这个链表中的一个随机节点或者NULL
//现在要求实现复制这个链表，返回复制后的新链表。 
//复杂链表的结构

//typedef struct ComplexNode
//{
//	DataType _data; // 数据 
//	struct ComplexNode * _next; // 指向下一个节点的指针 
//	struct ComplexNode * _random; // 指向随机节点（可以是链表中的任意节点 or 空） 
//}ComplexNode;  


