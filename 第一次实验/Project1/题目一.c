#include<stdio.h>
//����·����ӡ����
void print(char x, char y)
{
	printf("%c->%c\n", x, y);
}
//���庺ŵ������
void move(int n, char start, char temp ,char end)
{
	if (n <= 0)
	{
		printf("�������룡");
	}//����������
	else if (n == 1)
	{
		print(start, end);
	}//ֻʣһ������Բ��ʱ��ֱ���ƶ��������
	else
	{
		move(n - 1, start, end, temp);//��һ���Ƚ�����n-1�����Ӵ�start���ӽ���end�����ƶ���temp������
		print(start, end);//���������Ӵ�start�ƶ���end
		move(n - 1, temp, start, end);//����temp�����ϵ�n-1�����Ӵ�temp���ӽ���start�����ƶ���end������
	}
}
int main()
{
	int n;
	printf("�����뺺ŵ���Ĳ�����\n");
	scanf_s("%d", &n);
	move(n, 'A', 'B', 'C');
	return 0;
}