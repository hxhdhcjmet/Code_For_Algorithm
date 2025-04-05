#include<iostream>
using namespace std;
class Node//创建节点类
{
public:
	int coefficient;
	unsigned int frequency;
	Node* next;//创建属性项数，次数，下一个节点信息
	Node(int a,unsigned int b)//含项数和系数的构造函数，简化添加节点的步骤
	{
		coefficient = a;
		frequency = b;
		this->next = nullptr;
	}
	Node()//默认构造函数
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
	Node* gettail()//返回多项式链表的尾部
	{
		Node* p = new Node();
		p = head;
		while (p->next!= nullptr)
		{
			p = p->next;
		}
		return p;
	}
	void insertNode(int a, unsigned int b)//从尾部插入
	{
		Node* p = new Node(a, b);
		Node* q = gettail();
		q->next = p;
		
	}
	void list()//遍历多项式链表，分行输出项数和系数
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
		cout << "Enter the length of your link:" << endl;//输入多项式的项数，分别提示填入系数和次数
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
		while (p != nullptr || q != nullptr)//p,q两个多项式都不为空
		{
			if (p->frequency > q->frequency)//p第一个次数更高
			{
				result->insertNode(p->coefficient, p->frequency);
				p = p->next;
			}
			else if (p->frequency < q->frequency)//q第一个次数更高
			{
				result->insertNode(q->coefficient, q->frequency);
				q = q->next;
			}
			else//p,q的第一个次数相同
			{
				int sum = p->coefficient + q->coefficient;
				if (sum != 0)//系数不为零的才记录在和多项式中
				{
					result->insertNode(sum, p->frequency);
				}
				p = p->next;
				q = q->next;
			}
		}
		//当p,q中开始出现有空的时候，直接将另一个加到和多项式即可
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