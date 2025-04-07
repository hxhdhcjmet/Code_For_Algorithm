#include<iostream>
using namespace std;
class Node//�����ڵ���
{
public:
	int coefficient;
	unsigned int frequency;
	Node* next;//����������������������һ���ڵ���Ϣ
	Node(int a,unsigned int b)//��������ϵ���Ĺ��캯��������ӽڵ�Ĳ���
	{
		coefficient = a;
		frequency = b;
		this->next = nullptr;
	}
	Node()//Ĭ�Ϲ��캯��
	{
		coefficient = frequency = 0;
		next = nullptr;
	};
};
class Linkedlist
{
public:
	Node* head;
	Linkedlist()
	{
		head = new Node();
	}
	Node* gettail()//���ض���ʽ�����β��
	{
		Node* p = new Node();
		p = head;
		while (p->next!= nullptr)
		{
			p = p->next;
		}
		return p;
	}
	void insertNode(int a, unsigned int b)//��β������
	{
		Node* p = new Node(a, b);
		Node* q = gettail();
		q->next = p;
		
	}
	void list()//��������ʽ�����������������ϵ��
	{
		Node* p = head->next;
		while (p != nullptr)
		{
			cout << "coefficient:" << p->coefficient << " " << "frequency:" << p->frequency << endl;
			p = p->next;
		}
	}
	void initiallist()
	{
		int n;
		cout << "Enter the length of your link:" << endl;//�������ʽ���������ֱ���ʾ����ϵ���ʹ���
		cin >> n;
		while (n != 0)
		{
			int coefficient;
			unsigned int frequency;
			cout << "Enter the coefficient:" << endl;
			cin >> coefficient;
			cout << "Enter the frequency:" << endl;
			cin >> frequency;
			this->insertNode(coefficient, frequency);
			n--;
		}
		
		cout << "success!" << endl;
	}
	Linkedlist* add(Linkedlist* otherhead)
	{
		Linkedlist* result = new Linkedlist();
		Node* p = this->head->next;
		Node* q = otherhead->head->next;
		while (p != nullptr || q != nullptr)//p,q��������ʽ����Ϊ��
		{
			if (p->frequency > q->frequency)//p��һ����������
			{
				result->insertNode(p->coefficient, p->frequency);
				p = p->next;
			}
			else if (p->frequency < q->frequency)//q��һ����������
			{
				result->insertNode(q->coefficient, q->frequency);
				q = q->next;
			}
			else//p,q�ĵ�һ��������ͬ
			{
				int sum = p->coefficient + q->coefficient;
				if (sum != 0)//ϵ����Ϊ��Ĳż�¼�ںͶ���ʽ��
				{
					result->insertNode(sum, p->frequency);
				}
				p = p->next;
				q = q->next;
			}
		}
		//��p,q�п�ʼ�����пյ�ʱ��ֱ�ӽ���һ���ӵ��Ͷ���ʽ����
		while (p != nullptr)
		{
			result->insertNode(p->coefficient, p->frequency);
			p = p->next;
		}
		while (q != nullptr)
		{
			result->insertNode(q->coefficient, q->frequency);
			q = q->next;
		}
		return result;
	}
};
int main()
{
	Linkedlist *a=new Linkedlist();
	Linkedlist* b = new Linkedlist();
	a->initiallist();
	b->initiallist();
	Linkedlist *result= a->add(b);
	result->list();
	return 0;

}