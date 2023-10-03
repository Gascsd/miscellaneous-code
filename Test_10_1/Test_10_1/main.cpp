//
//  main.cpp
//  Test_10_1
//
//  Created by zht on 2023/10/1.
//

#include <iostream>
using namespace std;

//class A//只能在堆上创建对象
//{
//public:
//    A* GetObj()
//    {
//        return new A;
//    }
//private:
//    A() {}
//};

//int main()
//{
////    int s, x;
////    cin >> s >> x;
////    int distance = 0;
////    int time = 0;
////    while()
////    {
////        s += 7 * pow(0.98, time);
////        time++;
////    }
//    cout << sizeof(long) << endl;
//    return 0;
//}


//class Date
//{
//public:
//    // 获取某年某月的天数
//    bool is_leap_year(int year)
//    {
//        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
//    }
//    int GetMonthDay(int year, int month)
//    {
//        int arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//        if(month != 2)
//        {
//            return arr[month];
//        }
//        else
//        {
//            if(is_leap_year(year))
//            {
//                return arr[month] + 1;
//            }
//            else
//            {
//                return arr[month];
//            }
//        }
//    }
//    // 全缺省的构造函数
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    // 拷⻉构造函数
//    // d2(d1)
//    Date(const Date& d)
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//    // 赋值运算符重载
//    // d2 = d3 -> d2.operator=(&d2, d3)
//    Date& operator=(const Date& d)
//    {
//        if(this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//    // 析构函数
//    ~Date()
//    {
//        _year = -1;
//        _month = -1;
//        _day = -1;
//    }
//    // 日期+=天数
//    Date& operator+=(int day)
//    {
//        _day += day;
//        int tmp = GetMonthDay(_year, _month);
//
//        while(_day > tmp)
//        {
//            _day -= tmp;
//            _month += 1;
//            if(_month / 12 == 1 && _month % 12 == 1)
//            {
//                _year++;
//                _month = 1;
//            }
//            tmp = GetMonthDay(_year, _month);
//        }
//        return *this;
//    }
//    // 日期+天数
//    Date operator+(int day)
//    {
//        Date tmp(*this);
//        tmp += day;
//        return tmp;
//    }
//    // 日期-天数
//    Date operator-(int day)
//    {
//        Date tmp(*this);
//        tmp -= day;
//        return tmp;
//    }
//    // 日期-=天数
//    Date& operator-=(int day)
//    {
//        _day -= day;
//        while(_day <= 0)
//        {
//            if(_month == 1)
//            {
//                _month = 13;
//                _year--;
//            }
//            int tmp = GetMonthDay(_year, _month - 1);
//            _day += tmp;
//        }
//        return *this;
//    }
//    // 前置++
//    Date& operator++()
//    {
////        _day++;
////        if(GetMonthDay(_year, _month) < _day)
////        {
////            _day = 1;
////            _month++;
////            if(_month == 13)
////            {
////                _month = 1;
////                _year++;
////            }
////        }
//        *this += 1;
//        return *this;
//    }
//    // 后置++
//    Date operator++(int)
//    {
//        Date tmp(*this);
//        *this += 1;
//        return tmp;
//    }
//    // 后置--
//    Date operator--(int)
//    {
//        Date tmp(*this);
//        *this -= 1;
//        return tmp;
//    }
//    // 前置--
//    Date& operator--()
//    {
//        *this -= 1;
//        return *this;
//    }
//    // >运算符重载
//    bool operator>(const Date& d)
//    {
//        if(_year > d._year) return true;
//        if(_year == d._year && _month > d._month) return true;
//        if(_year == d._year && _month == d._month && _day > d._day) return true;
//        return false;
//    }
//    // ==运算符重载
//    bool operator==(const Date& d)
//    {
//        return _year == d._year && _month == d._month && _day == d._day;
//    }
//    // >=运算符重载
//    bool operator >= (const Date& d)
//    {
//        return *this > d || *this == d;
//    }
//    // <运算符重载
//    bool operator < (const Date& d)
//    {
//        return !(*this >= d);
//    }
//    // <=运算符重载
//    bool operator <= (const Date& d)
//    {
//        return !(*this > d);
//    }
//    // !=运算符重载
//    bool operator != (const Date& d)
//    {
//        return !(*this == d);
//    }
//    // 日期-日期 返回天数
//    int operator-(Date d)
//    {
//        Date max(*this);
//        Date min(d);
//        int flag = 1;
//        if(d > max)
//        {
//            max = d;
//            min = *this;
//            flag = -1;
//        }
//        int count = 0;
//        while(max != min)
//        {
//            min++;
//            count++;
//        }
//        return count * flag;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};


int fib(int n)
{
    if(n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void test1(int n)
{
    int count = 10;
    while(count--)
    {
        int* p = new int[n];
        delete[] p;
    }
    
}

int main()
{
    cout << fib(50) << endl;
    return 0;
}
