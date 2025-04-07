#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		this->next = nullptr;
	}
	Node(int value, Node* p)
	{
		data = value;
		this->next = p;
	}
	Node(int value)
	{
		data = value;
		this->next = nullptr;
	}
};
class Linkedlist
{
public:
	Node *head;
	Linkedlist()
	{
		head = new Node();
	}
	Node* gettail()
	{
		Node* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		return p;
	}
	void insert(int value)//��β��׷��
	{
		Node* p = new Node(value);
		Node* q = gettail();
		q->next = p;
	}
	void simple_insert(int n)//�򵥳�ʼ��������ֵ
	{
		for (int i = 1; i < n+1; i++)
		{
			insert(i);
		}
	}
	int getlen()
	{
		int i = 0;
		Node* p = head->next;
		while (p != nullptr)
		{
			p = p->next;
			i++;
		}
		
		return i;
	}
	void  bubble_sort()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}
		int n = this->getlen();
		Node* last = nullptr;
		for (int i = 0; i < n - 1; i++)//���ѭ��n-1��
		{
			bool swap = false;
			Node* current = head->next;
			while (current->next != last)//ѭ����β��Ϊֹ
			{
				if (current->data < current->next->data)
				{
					int temp = current->data;
					current->data = current->next->data;
					current->next->data = temp;
					swap = true;
				}
				current = current->next;
			}
			last = current;//����last��λ��
			if (!swap)//��һ�ֶ�û�з����������Ѿ�������ǰ����ѭ��
			{
				break;
			}

		}
		
		
	}
	Linkedlist* add(Linkedlist* others)
	{
		this->gettail()->next = others->head->next;
		return this;

	}
	//int* turn_to_arr()
	//{
	//	Node* p = head->next;
	//	int len = getlen();
	//	int* arr = new int[len];
	//	for (int i = 0; i < len; i++)
	//	{
	//		arr[i] = p->data;
	//		p = p->next;
	//	}
	//	return arr;
	//}
	//int* add(Linkedlist* others)
	//{
	//	Node* p = head;
	//	Node* q = others->head;
	//	int len1 = this->getlen();
	//	int len2 = others->getlen();
	//	int* a = this->turn_to_arr();
	//	int* b = others->turn_to_arr();
	//	int* c = new int[len1 + len2 ];
	//	for (int i = 0; i < len1; i++)
	//	{
	//		c[i] = a[i];
	//	}
	//	for (int j = 0; j < len2; j++)
	//	{
	//		c[len1 + j] = b[j];
	//	}
	//	for (int i = 0; i < len1 + len2-1;i++)
	//	{
	//		for (int j = 0; j < len1 + len2 - i - 1; j++)
	//		{
	//			if (c[j] < c[j + 1])
	//			{
	//				int temp = c[j];
	//				c[j] = c[j + 1];
	//				c[j + 1] = temp;
	//			}
	//		}
	//	}//�Ӵ�С����
	//	return c;
	//}
	//Linkedlist* turn_to_Linkedlist(int *p,int n)
	//{
	//	Linkedlist* q = new Linkedlist();
	//	for (int i = 0; i < n; i++)
	//	{
	//		q->insert(p[i]);
	//	}
	//	return q;
	//}������תΪ���飬�ٽ�����ð����������������ת��������˼ά�򵥣�������̫��
	void list()
	{
		Node* p = head;
		while (p->next != nullptr)
		{
			cout << p->next->data << endl;
			p = p->next;
		}
	}
};
int main()
{
	Linkedlist* p = new Linkedlist();
	Linkedlist* q = new Linkedlist();
	q->simple_insert(8);
	p->simple_insert(5);
	p->add(q);
	p->bubble_sort();
	p->list();
	

	return 0;

}