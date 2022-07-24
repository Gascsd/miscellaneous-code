#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fib(n - 1) + Fib(n - 2);
}
int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    int i = 0;
    int n = 0;
    int ret = 0;
    scanf("%d", &n);
    while (1)
    {
        if (Fib(i) < n && Fib(i + 1) > n)
        {
            ret = min(n - Fib(i), Fib(i + 1) - n);
            break;
        }
        i++;
    }
    printf("%d", ret);
    return 0;
}