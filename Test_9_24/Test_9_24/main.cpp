//
//  main.cpp
//  Test_9_24
//
//  Created by zht on 2023/9/24.
//

#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
};

class Date
{
public:
    Date(int year = 1970, int month = 1, int day = 1)//构造函数
    {
        _year = year;
        _month = month;
        _day = day;
        cout << "Date(int year, int month, int day)" << endl;
    }
    void Print()//其他成员函数
    {
        //cout << "A:" << _a << endl;
        cout << _year << "年" << _month<< "月" << _day << "日" << endl;
    }
    ~Date()//析构函数
    {
        cout << "~Date()" << endl;
    }
    
    Date(Date& d)//拷贝构造函数
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
        cout << "Date(Date& d)" << endl;
    }
    int operator-(Date& d)
    {
        return _day - d._day;
    }
    Date& operator=(const Date& d)
    {
        if(this != &d)
        {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        return *this;
    }
private:
    //A _a;
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1(2023, 9, 24);
    Date d2(2023, 9 ,23);
    d1.Print();
    d2.Print();
    Date d3(d1);
    d2 = d3;
    
    cout << d2.operator-(d1) << " == " << d2 - d1 << endl;
    
    
//    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
//    int* p1 = arr;
//    int* p2 = p1;
//    int arr2[10];
//
//    for(int i = 0;i <10; i++)
//    {
//        arr2[i] = arr[i];
//    }
//    p2 = arr2;
    //引用:给变量取别名
//    int a = 10;
//    int& b = a;
//    a = 15;
//    cout << a  << ":" << b << endl;
    

    return 0;
}



