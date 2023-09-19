//
//  test.cpp
//  Test_9_18
//
//  Created by zht on 2023/9/18.
//

#include "test.hpp"


size_t mystrlen(char str[])
{
    char* tmp = str;
    while(*tmp!='\0')
    {
        tmp++;
    }
    return tmp-str;
}


void test1()
{
    char str[] = "hello world";
    size_t size = mystrlen(str);
    cout << size << endl;
}

#include <cstdio>

void test2()
{
    //int* p = new int[1024*1024*1024*2];
//    vector<int> v;
//    int tmp;
//    while(scanf("%d", &tmp) != EOF)
//    {
//        v.push_back(tmp);
//    }
//    reverse(v.begin(), v.end());
//    for(auto& e : v)
//    {
//        cout << e << " ";
//    }
}

//int* get(int n)
//{
//    int a = 10;
//    return &a;
//}
//
//void test3()
//{
//    int* p = get(10);
//    p = 0;
//}

char* myreverse(char* str)
{
    char* left = str;
    char* right = str + strlen(str) - 1;
    while(left < right)
    {
        char ch = *left;
        *left = *right;
        *right = ch;
        left++;
        right--;
    }
    return str;
}


int main_test()
{
    //cout << "main_test" << endl;
    test2();
    return 0;
}
