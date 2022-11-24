#define _CRT_SECURE_NO_WARNINGS 1
//计算糖果
//#include<stdio.h>
//int main()
//{
//    int val[4] = { 0 };
//    int A, B, C;
//    for (int i = 0; i < 4; i++)
//    {
//        scanf("%d", &val[i]);
//    }
//    A = (val[0] + val[2]) / 2;
//    B = (val[2] - val[0]) / 2;
//    C = val[3] - B;
//    if (B - C == val[1])
//    {
//        printf("%d %d %d", A, B, C);
//    }
//    else
//    {
//        printf("No");
//    }
//    return 0;
//}

//进制转换
#include<stdio.h>
int main()
{
    int M = 0, N = 0;
    scanf("%d %d", &M, &N);
    char arr[10000] = { 0 };
    int i = 0;
    while (M)
    {
        int a = M % N;
        char ch = 0;
        if (a > 9)
        {
            ch = a - 10 + 'A';
        }
        else
        {
            ch = a + '0';
        }
        arr[i] = ch;
        M /= N;
        i++;
    }
    for (; i >= 0; i--)
    {
        printf("%c", arr[i]);
    }
    return 0;
}