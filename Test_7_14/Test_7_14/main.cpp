#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include "mystring.hpp"
#include "test_list.h"
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
    zht::list<zht::string> lt;
    //list<zht::string> lt;

    cout << "--------------" << endl;
    zht::string s1("1111");
    cout << "--------------" << endl;
    lt.push_back(s1);
    cout << "--------------" << endl;

    lt.push_back(move(s1));
}

void Func(int& x)
{
    cout << "lvalue reference" << endl;
}
void Func(int&& x)
{
    cout << "rvalue reference " << endl;
}
void Func(const int& x)
{
    cout << "const lvalue reference " << endl;
}
void Func(const int&& x)
{
    cout << "const rvalue reference " << endl;
}
template<class T>
void PerfectForward(T&& x)
{
    Func(std::forward<T>(x));
}
void Test7()
{
    PerfectForward(10); // 右值
    int a = 10;
    PerfectForward(a); //左值
    const int b = 8;
    PerfectForward(b); //const 左值
    PerfectForward(std::move(b)); //const右值
}

class Person
{
public:
    Person(const char* name = "", int age = 0)
        :_name(name)
        , _age(age)
    {}
    Person(const Person& p) = delete;
private:
    zht::string _name;
    int _age;
};

//void Test8()
//{
//    Person p1;
//    Person p2 = p1;
//    Person p3 = std::move(p1);
//    Person p4;
//    p4 = std::move(p2);
//}

class Date1
{
public:
    int _year;
    int _month;
    int _day;
};
class Date2
{
public:
    int _year = 1970;
    int _month = 1;
    int _day = 1;
};

//void Test9()
//{
//    Date1 d11;
//    Date2 d12;
//}

//template<class ...Args>
//void ShowList(Args... args)
//{
//    cout << sizeof...(args) << endl;
//}
////递归出口
//template<class T>
//void ShowList(const T& t)
//{
//    cout << t << endl;
//}
////递归过程
//template<class T, class ...Args>
//void ShowList(T value, Args... args)
//{
//    cout << value << " ";
//    ShowList(args...);//这里要使用...表示将参数包展开
//}

template<class T>
void PrintArgs(T t)
{
    cout << t << " ";
}
template<class... Args>
void ShowList(Args... args)
{
    int arr[] = { (PrintArgs(args), 0)... };
    cout << endl;
}
void Test10()
{
    ShowList(1);
    ShowList(1, 'A');
    ShowList(1, 'A', string("sort"));
}

void Test11()
{
    vector<int> v = { 1,2,3,4,6,5,9,8,7,10 };
    sort(v.begin(), v.end(), less<int>());
    for (auto& e : v)
    {
        cout << e << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), greater<int>());
    for (auto& e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}
struct Goods
{
    string _name; // 名字
    double _price; // 价格
    int _evaluate; // 评价
    Goods(const char* str, double price, int evaluate)
        :_name(str)
        , _price(price)
        , _evaluate(evaluate)
    {}
};
void Test12()
{
    vector<Goods> v = { {"apple",2.1,5},{"banana",3,4},{"orange",2.2,3}, {"pineapple",1.5,4 } };
    sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
        return g1._name < g2._name; });
    cout << "sort by name" << endl;
    for (auto& e : v)
    {
        cout << e._name << " " << e._price << " " << e._evaluate << endl;
    }
    cout << endl;
    sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
        return g1._price < g2._price; });
    cout << "sort by price" << endl;
    for (const auto& e : v)
    {
        std::cout << e._name << " " << e._price << " " << e._evaluate << endl;
    }
    cout << endl;
    sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
        return g1._evaluate < g2._evaluate; });
    cout << "sort by evaluate" << endl;
    for (const auto& e : v)
    {
        cout << e._name << " " << e._price << " " << e._evaluate << endl;
    }
    cout << endl;
}

int main()
{
    Test12();
    return 0;
}
