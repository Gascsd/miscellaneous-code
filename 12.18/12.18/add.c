#define _CRT_SECURE_NO_WARNINGS 1

int g_val = 99;//全局变量是有外部链接属性的
//static修饰	全局变量就屏蔽了它的外部链接属性


static int Add(int x, int y)//屏蔽了它的外部链接属性
{
	return x + y;
}