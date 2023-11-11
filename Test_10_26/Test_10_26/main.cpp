//
//  main.cpp
//  Test_10_26
//
//  Created by zht on 2023/10/26.
//

#include <iostream>
using namespace std;

// 1 1 2 3
//f(n) = f(n-1) + f(n-2);
//f(n-1) = f(n-2) + f(n-3)
//f(n-2) = f(n-3) + f(n-4);

int fib(int n)
{
    if(n == 1 || n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

int dfs(int n)
{
    if(n == 1 || n == 2) return n;
    return dfs(n - 1) + dfs(n - 2);
}

int main()
{
    cout << fib(5) << endl;
    return 0;
}
