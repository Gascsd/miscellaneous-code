//
//  main.cpp
//  Test_8_6
//
//  Created by zht on 2023/8/6.
//

#include <iostream>
using namespace std;

int Div(int a, int b)
{
    if(b == 0)
    {
        throw "the second num is 0";
    }
    else
    {
        return a / b;
    }
}

void Func()
{
    int a, b;
    cin >> a >> b;
    cout << Div(a, b) << endl;
}

int main()
{
    try {
        Func();
    } catch (const char* errmsg) {
        cout << errmsg << endl;
    }
    return 0;
}
