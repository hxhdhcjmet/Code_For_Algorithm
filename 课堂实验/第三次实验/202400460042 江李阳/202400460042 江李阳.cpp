#include<iostream>
#include<cstring>
using namespace std;
int level(char c)
{
	if (c == '*')
	{
		return 4;
	}
	else if (c == '/')
	{
		return 3;
	}
	else if (c == '+')
	{
		return 2;
	}
	else if (c == '-')
	{
		return 1;
	}
	else if (c == ' ')
	{
		return -1;
	}
	return 0;
}
class Data
{
public:
	int data;
	Data* next;
	Data()
	{
		data = 0;
		next = nullptr;
	}
	Data(int n)
	{
		data = n;
		next = nullptr;
	}
};
class Compute
{
public:
	Data* head;
	int len;
	Compute()
	{
		head = new Data();
		len = 0;
	}
	void push(int n)
	{
		Data* p = new Data(n);
		p->next = head->next;
		head->next = p;
		len++;
	}
	Data* pop()//��ջ
	{
		if (head->next != nullptr)
		{
			Data* q = head->next;
			head->next = q->next;
			len--;
			return q;
			
		}
		cout << "empty stack!" << endl;
		return nullptr;

	}
	bool isEmpty()//�ж��Ƿ�Ϊ��
	{
		if (head->next == nullptr)
		{
			return true;
		}
		return false;
	}
	bool isOperatable()//�ж��ܷ��������,��ջ������������Ԫ��
	{
		if (len >= 2)
		{
			return true;
		}
		return false;
	}
	int getTop()
	{
		if(!this->isEmpty())
		{
			return head->next->data;
		}
		cout << "fail,empty stack!" << endl;
		return 0;
	}
	int operate()
	{
		char c;
		int num = 0;
		bool reading = false;
		while (cin.get(c) && c != '#')
		{
			int n = level(c);//������������ݻ��ֵȼ���ȷ����һ������
			if (isdigit(c))
			{
				if (!reading)//��һ�ζ�ȡ������
				{
					num = 0;
				}
				num = num * 10 + (c - '0');
				reading = true;
				continue;
			}
			else
			{
				if (reading)
				{
					this->push(num);
					num = 0;
					reading = false;
				}
			}
			if (n > 0) {
				if (!this->isOperatable())
				{
					cout << "no enough data!" << endl;
					break;
				}
				int a = this->pop()->data;//�Ƚ�����������Ҳ�����
				int b = this->pop()->data;//�������
				//������������ǰ��������
				switch (n)
				{
				case 1:
				{
					int c = b - a;
					this->push(c);//������ѹջ
					break;
				}
				case 2:
				{
					int c = a + b;
					this->push(c);
					break;

				}
				case 3:
				{
					if (a == 0)
					{
						cout << "WRONG!division cant be 0!" << endl;
						break;
					}
					int c = b / a;
					this->push(c);
					break;
				}
				case 4:
				{
					int c = a * b;
					this->push(c);
					break;
				}
				}
			}

		}
		return this->getTop();
	}
};
int main()
{
	Compute* a = new Compute();
	cout << a->operate();
	return 0;
}