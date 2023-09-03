//
//  main.cpp
//  Test_9_2
//
//  Created by zht on 2023/9/2.
//

#include <iostream>
using namespace std;


int fib(int n)
{
    if(n == 0 || n == 1) return  n;
    return fib(n-1) + fib(n-2);
}

int main()
{
    cout << fib(10000) << endl;
    return 0;
}
