//
//  main.cpp
//  Test_9_22
//
//  Created by zht on 2023/9/22.
//

#include <iostream>
using namespace std;

//class Student
//{
//    string _name;
//    int _age;
//    float _grade;
//
//public:
//    void PrintName()
//    {
//        cout << _name << endl;
//    }
//    void ChangeName(string newName)
//    {
//        _name = newName;
//    }
//    void Init(string name, int age, float grade)
//    {
//        _name = name;
//        _age = age;
//        _grade = grade;
//    }
//    void Print()
//    {
//        cout << "姓名:" << _name << " 年龄:"  << _age << " 成绩:" << _grade << endl;
//    }
//
//};
//
//
//
////void Print(Student s)
////{
////    cout << "姓名:" << s.name << " 年龄:"  << s.age << " 成绩:" << s.grade << endl;
////}
//
//int main()
//{
//    Student s1;
//    s1.Init("张三", 18, 80.0);
//    //Print(s1);
//    s1.Print();
//    //cout << s1._name << endl;
//    s1.ChangeName("李四");
//    s1.PrintName();
//    return 0;
//}



class Date
{
public:
    void Init(int year, int month, int day)
    {
        //cout << this << endl;
        _year = year;
        _month = month;
        _day = day;
    }
    
    //类里面每个函数都会默认传一个参数this，他的类型是类的指针类型（Date*），这个参数我们不能显示的写出来，是编译器默认传的参数，但是我们可以在函数里面显示的用
    //this指针就是调用这个函数的对象的地址
    void Print()
    {
        cout << this << endl;
        cout << this->_year << "年" << this->_month << "月" << this->_day << "日" << endl;
    }
    
private:
    int _year;
    int _month;
    int _day;
};
//类大小计算规则
//1. 只关注成员变量的大小
//2. 计算方法与C语言的结构体计算方法一样
//3. 如果一个类中没有成员变量，只有成员函数，那么这个类的大小是1个字节，我们把这个字节叫做占位符

class A
{
    void Print()
    {
        cout << "hello world" << endl;
    }
};

int main()
{
    Date d1;
    d1.Init(1970, 1, 1);
    Date d2;
    d2.Init(2023, 9, 22);
    
    cout << &d1 << endl;
    d1.Print();
    cout << &d2 << endl;
    d2.Print();
    return 0;
}
