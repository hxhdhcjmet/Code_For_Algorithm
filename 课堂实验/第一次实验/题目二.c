#include<stdlib.h>
#include<stdio.h>
//补充以下函数的参数和代码，构造swap函数，实现两个数的交换
void swap(int *a,int *b)
{
	int temp;//创建中间临时变量
	temp = *a;
	*a = *b;
	*b = temp;//交换两个数的地址所代表的变量的值
}
int main() {
	int a = 15;
	int b = 10;
	swap(&a,&b);
	printf("%d\t%d", a, b);
	return 0;
}
