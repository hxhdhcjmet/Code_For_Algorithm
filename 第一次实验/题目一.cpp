#include<stdio.h>
void move(int n,char A,char B,char C )
{
	if (n <= 0)
	{
		printf("错误圆盘个数");
		return 0;
	}//处理错误输入
	else if (n ==1)
	{
		printf("将这个圆盘从%c,移动到%c",A,C);
		return 0;
	}//处理只有一个时的特殊情况
	else
	{
		move(n - 1, A, C, B);
		printf("将第%d个盘子从%c移动到%c", n - 1, A, C);
		move(n - 1, B, A, C);

		
	}
}
int main()
{
	int n;
	printf("请输入盘子的数量");
	scanf("%d", &n);
	move(n, 'A', 'B', 'C');
	return 0; 
}