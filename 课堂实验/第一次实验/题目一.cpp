#include<stdio.h>
void move(int n,char A,char B,char C )
{
	if (n <= 0)
	{
		printf("����Բ�̸���");
		return 0;
	}//�����������
	else if (n ==1)
	{
		printf("�����Բ�̴�%c,�ƶ���%c",A,C);
		return 0;
	}//����ֻ��һ��ʱ���������
	else
	{
		move(n - 1, A, C, B);
		printf("����%d�����Ӵ�%c�ƶ���%c", n - 1, A, C);
		move(n - 1, B, A, C);

		
	}
}
int main()
{
	int n;
	printf("���������ӵ�����");
	scanf("%d", &n);
	move(n, 'A', 'B', 'C');
	return 0; 
}