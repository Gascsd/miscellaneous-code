#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


void* my_memmove(void* dst, const void* src, size_t count)
{
    void* ret = dst;
    if (dst <= src || (char*)dst >= ((char*)src + count)) 
    {
        while (count--) 
        {
            *(char*)dst = *(char*)src;
            dst = (char*)dst + 1;
            src = (char*)src + 1;
        }
    }
    else 
    {
        dst = (char*)dst + count - 1;
        src = (char*)src + count - 1;
            while (count--) 
            {
                *(char*)dst = *(char*)src;
                dst = (char*)dst - 1;
                src = (char*)src - 1;
            }
    }
    return ret;
}


int main()
{
    int arr[] = { 1,2,3,4,5,6,7 };
    int i = 0;
    my_memmove(arr + 3, arr, 16);
    for (i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}