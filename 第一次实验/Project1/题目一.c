#include<stdio.h>
//定义路径打印函数
void print(char x, char y)
{
	printf("%c->%c\n", x, y);
}
//定义汉诺塔函数
void move(int n, char start, char temp ,char end)
{
	if (n <= 0)
	{
		printf("错误输入！");
	}//检查错误输入
	else if (n == 1)
	{
		print(start, end);
	}//只剩一个最大的圆盘时，直接移动这个最大的
	else
	{
		move(n - 1, start, end, temp);//第一步先将上面n-1个盘子从start柱子借助end柱子移动到temp柱子上
		print(start, end);//将最大的盘子从start移动到end
		move(n - 1, temp, start, end);//将在temp柱子上的n-1个盘子从temp柱子借助start柱子移动到end柱子上
	}
}
int main()
{
	int n;
	printf("请输入汉诺塔的层数：\n");
	scanf_s("%d", &n);
	move(n, 'A', 'B', 'C');
	return 0;
}