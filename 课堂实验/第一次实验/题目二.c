#include<stdlib.h>
#include<stdio.h>
//�������º����Ĳ����ʹ��룬����swap������ʵ���������Ľ���
void swap(int *a,int *b)
{
	int temp;//�����м���ʱ����
	temp = *a;
	*a = *b;
	*b = temp;//�����������ĵ�ַ������ı�����ֵ
}
int main() {
	int a = 15;
	int b = 10;
	swap(&a,&b);
	printf("%d\t%d", a, b);
	return 0;
}
