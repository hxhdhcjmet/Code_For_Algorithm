#include<iostream>
using namespace std;
class Arr//����Arr������Ŷ���ʽ�ĳ��Ⱥ�������Ϣ
{
public:
	int* arr;
	int len;
	Arr()
	{
		arr = nullptr;
		len = 0;
	}//Ĭ�Ϲ��캯��
	Arr(int n)
	{
		cout << "The biggest frequency is "<< n <<endl;
		this->len = n + 1;
		arr = new int[len];//�����±�����������Ӧ�������ֵΪϵ���������ڵĴ���������ϵ��Ϊ0
		for (int i = 0; i < len; i++)
		{
			cout << "Enter the coefficient of frequency "<< i << endl;
			cin >> arr[i];
		}
	}//��������n�Ĺ��캯���������ݼ������n+1��ʹ�����ô�������
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
		}//������ͬ�������ϵ��
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
		}//ʣ�ಿ��ֱ�Ӹ��Ƴ��Ƚϳ����Ǹ���ϵ��
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