//1.两个有序链表，合并后依然有序
#include<iostream>
using namespace std;
typedef int DataType;
typedef struct ListNode
{
	ListNode* _next;
	DataType _data;
}ListNode;

ListNode*  BuyNode(DataType data)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_data = data;
	head->_next = NULL;
	return head;
}

void PushBack(ListNode*& head ,DataType data)
{
	if (head == NULL)
	{
		head = BuyNode(data);
		return;
	}
	ListNode* tmp = head;
	while (tmp->_next)
	{
		tmp = tmp->_next;
	}
	tmp->_next = BuyNode(data);
}

void Print(ListNode* head)
{
	if (head == NULL)
		return;
	ListNode* cur = head;
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->_next;
	}
	cout << endl;
}

ListNode* Merge(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	ListNode* newHead = NULL;
	ListNode* tmp = NULL;
	ListNode* tail = NULL;

	if (l1->_data < l2->_data)
		newHead = tail = l1;
	else
		newHead = tail = l2;

	while ((l1 != NULL) && (l2 != NULL))
	{
		if (l1->_data < l2->_data)
		{
			tmp = l1;
			l1 = l1->_next;
		}
		else
		{
			tmp = l2;
			l2 = l2->_next;
		}

		tail->_next = tmp;
		tail = tmp;
	}
	if (l1)
		tail->_next = l1;
	if (l2)
		tail->_next = l2;
	return newHead;
}


ListNode* RMerge(ListNode* l1, ListNode* l2)  //每次排序的时候注意要缩小范围，
                                              //一定要让newHead指向next,否则前面的结点会丢失。
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	ListNode* newHead = NULL;
	ListNode* tail = NULL;
	if (l1->_data < l2->_data)
	{
		newHead =l1;
		newHead->_next = RMerge(l1->_next, l2);
	}
	else
	{
		newHead = tail = l2;
		newHead->_next =RMerge(l1,l2->_next);
	}
	return newHead;
}




int main()
{
	/*ListNode* head=NULL;
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	PushBack(head, 5);
	Print(head);*/

	ListNode* l1 = NULL;
	ListNode* l2 = NULL;
	PushBack(l1, 1);
	PushBack(l1, 3);
	PushBack(l1, 5);
	PushBack(l2, 2);
	PushBack(l2, 4);
	PushBack(l2, 6);

	ListNode* ret = RMerge(l1, l2);
	Print(ret);
	ListNode* re = RMerge(l1, l2);
	Print(re);

	system("pause");
	return 0;
}



//2.实现1+2+3...+n，要求不能使用乘除法、循环、条件判断、选择相关的关键字。
//方案一：利用构造函数
//思路：累加其实就是将一个代码块重复了N次，构造函数在构造时也是这个原理
#include<iostream>
using namespace std;

class Count
{
public:
	Count()
	{
		++n;
		sum += n;
	}

  static unsigned int GetSum()
	{
		return sum;
	}
private:
	static unsigned int n;
	static unsigned int sum;
};

unsigned int Count::n = 0;
unsigned int Count::sum = 0;

int main()
{
	Count *a = new Count[100];
	unsigned int ret = a->GetSum();
	cout << ret<< endl;
	system("pause");
}
