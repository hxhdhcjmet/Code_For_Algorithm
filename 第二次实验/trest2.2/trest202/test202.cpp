#include<iostream>
using namespace std;
class Arr//创建Arr类来存放多项式的长度和数据信息
{
public:
	int* arr;
	int len;
	Arr()
	{
		arr = nullptr;
		len = 0;
	}//默认构造函数
	Arr(int n)
	{
		cout << "The biggest frequency is "<< n <<endl;
		this->len = n + 1;
		arr = new int[len];//数组下标代表次数，对应的数组的值为系数，不存在的次数的向令系数为0
		for (int i = 0; i < len; i++)
		{
			cout << "Enter the coefficient of frequency "<< i << endl;
			cin >> arr[i];
		}
	}//带最大次数n的构造函数，次数递减，最多n+1项，就创建这么大的数组
	void list()
	{
		int n = this->len;
		for (int i = n - 1; i >= 0; i--)
		{
			if (this->arr[i] != 0)
			{
				cout << "coefficient:" << this->arr[i] << " " << "frequency:" << i << endl;
			}

		}
	}
	Arr* add(Arr* other)
	{
		Arr* result = new Arr();
		int* p = this->arr;
		int* q = other->arr;
		int big = (this->len > other->len) ? this->len : other->len;
		int small = (this->len < other->len) ? this->len : other->len;
		result->arr = new int[big];
		result->len = big;
		for (int i = 0; i < small; i++)
		{
			result->arr[i] = p[i] + q[i];
		}//长度相同部分相加系数
		if (this->len > other->len)
		{
			for (int j = small; j < big; j++)
			{
				result->arr[j] = p[j];
			}
		}
		else if (this->len < other->len)
		{
			for (int j = small; j < big; j++)
			{
				result->arr[j] = q[j];
			}
		}//剩余部分直接复制长度较长的那个的系数
		return result;
	}
};
int main()
{
	Arr* a = new Arr(4);
	Arr* b = new Arr(3);
	Arr* c = new Arr();
	c = a->add(b);
	c->list();
	return 0;
}