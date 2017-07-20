//1.ɾ��һ����ͷ������ķ�β�ڵ�
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

//2.��β��ͷ��ӡ������
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

//3.��������ĸ��ơ�
//һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬����һ��randomָ��ָ����������е�һ������ڵ����NULL
//����Ҫ��ʵ�ָ�������������ظ��ƺ�������� 
//��������Ľṹ

typedef struct ComplexNode
{
	DataType _data; // ���� 
	struct ComplexNode * _next; // ָ����һ���ڵ��ָ�� 
	struct ComplexNode * _random; // ָ������ڵ㣨�����������е�����ڵ� or �գ� 
}ComplexNode;

ComplexNode* Buynode(DataType data)
{
	ComplexNode* cur = (ComplexNode*)malloc(sizeof(ComplexNode));
	cur->_next = NULL;
	cur->_data = data;
	cur->_random = NULL;
	return cur;
}

ComplexNode* Find(ComplexNode* head, DataType data)
{
	if (head == NULL)
		return NULL;
	ComplexNode* cur = head;
	while (cur)
	{
		if (cur->_data == data)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}

void PushBack(ComplexNode* head, DataType data)
{
	if (head == NULL)
	{
		head = Buynode(data);
		return;
	}
	ComplexNode* cur = head;
	while (cur->_next)
	{
		cur = cur->_next;
	}
	cur->_next = Buynode(data);
}


void CloneNode(ComplexNode* head)
{
	ComplexNode* cur = head;
	while (cur != NULL)
	{
		ComplexNode* cloneHead = new ComplexNode();  //�Ƚ�ԭ���Ľ�������ָ�붼���п���
		cloneHead->_data = cur->_data;
		cloneHead->_next = cur->_next;
		cloneHead->_random = NULL;

		cur->_next = cloneHead;
		cur = cloneHead->_next;
	}
}

void CloneRandom(ComplexNode* head) //�����ɽ����п���
{
	ComplexNode* cur = head;
	while (cur != NULL)
	{
		ComplexNode* cloneHead = cur->_next;
		if (cur->_random  != NULL)
		{
			cloneHead->_random = cur->_random->_next;
		}
		cur = cloneHead->_next;
	}
}

ComplexNode* ConnectList(ComplexNode* head)
{
	ComplexNode* cur = head;
	ComplexNode* newHead = NULL;
	ComplexNode* cloneNext = NULL;

	if (cur != NULL)   //���ҳ����Ե�ͷ
	{
		newHead = cloneNext = cur->_next;
		cur->_next = cloneNext->_next;
		cur = cur->_next;
	}

	while (cur != NULL)  //�ٽ����ԵĽ��ֱ�������
	{
		cloneNext->_next = cur->_next;
		cloneNext = cloneNext->_next;
		cur->_next = cloneNext->_next;
		cur = cur->_next;
	}
	return newHead;
}

void Print(ComplexNode* head)
{
	if (head == NULL)
		return;
	ComplexNode* cur = head;
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->_next;
	}
	cout << endl;
}

void testComplex()
{
	ComplexNode* head = NULL;
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	PushBack(head, 5);

	ComplexNode* next = Find(head, 2);
	ComplexNode* ran = Find(head, 4);
	next->_random = ran;

	ComplexNode* next2 = Find(head, 3);
	ComplexNode* ran1 = Find(head, 5);
	next2->_random = ran1;

	Print(head);

	CloneNode(head);
	CloneRandom(head);
	ComplexNode* newHead = ConnectList(head);

	Print(newHead);
	
}


int main()
{
	//testDel
	//testPrint();
	testComplex();
	system("pause");
	return 0;
}