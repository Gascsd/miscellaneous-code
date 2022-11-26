#define _CRT_SECURE_NO_WARNINGS 1
//统计回文


//连续最大和
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int len = 0;
    scanf("%d", &len);
    int* arr = (int*)malloc(sizeof(int) * len);
    if (arr == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    int i = 0;
    int sum = 0, max_sum = 0;
    while (i < len - 1)
    {
        sum = 0;
        if (arr[i] + 1 == arr[i + 1])
        {
            while (arr[i] + 1 == arr[i + 1] && i < len - 1)
            {
                sum += arr[i + 1];
                i++;
            }
        }
        else if (arr[i] - 1 == arr[i + 1])
        {
            while (arr[i] - 1 == arr[i + 1] && i < len - 1)
            {
                sum += arr[i + 1];
                i++;
            }
        }
        if (max_sum < sum)
        {
            max_sum = sum;
        }
        i++;
    }
    printf("%d\n", max_sum);
    return 0;
}