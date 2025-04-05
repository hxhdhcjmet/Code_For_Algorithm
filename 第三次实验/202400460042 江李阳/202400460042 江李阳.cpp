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
	Data* pop()//出栈
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
	bool isEmpty()//判断是否为空
	{
		if (head->next == nullptr)
		{
			return true;
		}
		return false;
	}
	bool isOperatable()//判断能否进行运算,及栈内至少有两个元素
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
			int n = level(c);//根据输入的内容划分等级，确定下一步动作
			if (isdigit(c))
			{
				if (!reading)//第一次读取到数字
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
				int a = this->pop()->data;//先进后出，这是右操作数
				int b = this->pop()->data;//左操作数
				//弹出操作符号前面两个数
				switch (n)
				{
				case 1:
				{
					int c = b - a;
					this->push(c);//运算结果压栈
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