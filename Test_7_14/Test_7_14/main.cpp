#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <list>
#include "mystring.hpp"
using namespace std;

//void Test1()
//{
//    //左值
//    int a = 1;
//    double x = 1.1, y = 2.2;
//    int* pb = new int(10);
//    const int c = 2;
//    //左值引用
//    int& ra = a;
//    int*& rpb = pb;
//    const int& rc = c;
//    int& pvalue = *pb;
//    //右值
//    10;
//    x + y;
//    min(x, y);
//    //右值引用
//    int&& rr1 = 10;
//    int&& rr2 = x + y;
//    int&& rr3 = min(x, y);
//}

void Test2()
{
    int x = 1, y = 2;
    int&& rr1 = x + y;
    cout << "x + y:" << x + y << endl;
    cout << "rr1:" << rr1 << endl;
    rr1 = 10;
    cout << "rr1" << rr1 << endl;
}
//void Test3()
//{
//    int a = 10;
//    int& ra1 = a;
//    int& ra2 = 10;//右值引用不能引用左值，因此这行代码报错
//
//    const int& ra3 = 10;
//    const int& ra4 = a;
//}
//void Test4()
//{
//    //右值引用只能引用右值，不能引用左值
//    int&& r1 = 10;
//    int a = 10;
//    //int&& r2 = a;//右值引用引用左值报错
//    //Xcode报错内容：Rvalue reference to type 'int' cannot bind to lvalue of type 'int'
//    //右值引用能引用move之后的左值
//    int&& r3 = std::move(a);
//}

template<class T>
T func(const T& val)
{
    T ret;
    //...
    return ret;
}




void Test5()
{
    zht::string str;
    str = zht::to_string(-1234);
}

void Test6()
{
    list<zht::string> lt;
    zht::string s1("1111");

    cout << "--------------" << endl;

    lt.push_back(s1);

    cout << "--------------" << endl;

    lt.push_back(move(s1));
}

int main()
{
    Test6();
    return 0;
}
