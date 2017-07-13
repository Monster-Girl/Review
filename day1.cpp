//1.�������������ϲ�����Ȼ����
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


ListNode* RMerge(ListNode* l1, ListNode* l2)  //ÿ�������ʱ��ע��Ҫ��С��Χ��
                                              //һ��Ҫ��newHeadָ��next,����ǰ��Ľ��ᶪʧ��
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



//2.ʵ��1+2+3...+n��Ҫ����ʹ�ó˳�����ѭ���������жϡ�ѡ����صĹؼ��֡�
//����һ�����ù��캯��
//˼·���ۼ���ʵ���ǽ�һ��������ظ���N�Σ����캯���ڹ���ʱҲ�����ԭ��
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
