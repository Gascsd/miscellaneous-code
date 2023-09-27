//
//  main.cpp
//  Test_9_27
//
//  Created by zht on 2023/9/27.
//

//#include <iostream>
//using namespace std;
//
//
//
//
//class Date
//{
//public:
//    friend ostream& operator<<(ostream& out, Date d);//将operator<<声明为友元函数，保证这个函数能够访问到类里面私有的成员
//    friend istream& operator>>(istream& in, Date& d);
//    Date(int year = 1970, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//        cout << "Date(int year = 1970, int month = 1, int day = 1)" << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
////1. 为什么在类外面写：因为我们要保证传进来的第一个参数是ostream类型的
////2. 这个out是ostream类型的一个对象（这里的out和我们日常使用的cout是一样的，只是cout是一个全局的对象）
////ostream是一个类型
//ostream& operator<<(ostream& o, Date d)
//{
//    o << d._year << "年"  << d._month << "月" << d._day << "日" << endl;
//    return o;
//}
////1. 写一个运算符重载的函数(写在类外)
////2. 将这个运算符重载的函数设为该类的友元函数
//istream& operator>>(istream& in, Date& d)
//{
//    in >> d._year >> d._month >> d._day;
//    return in;
//}
//
//int main()
//{
//    Date d1;
//    cin >> d1;
//    cout << d1;
//    cout << int(5) << float(1.5) << endl;
//    return 0;
//}


/********************************************************************************************************************************************/

//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//    A()
//    {
//        cout << "A()" << endl;
//    }
//    A(A& a)
//    {
//        cout << "A(A& a)" << endl;
//    }
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//};
//
//class Date
//{
//public:
//    Date(int year = 1970, int month = 1, int day = 1)
//    {
//        _ptr = new int[10];
//        _year = year;
//        _month = month;
//        _day = day;
//        cout << "Date(int year = 1970, int month = 1, int day = 1)" << endl;
//    }
//    Date(const Date& d)
//    {
//        _ptr = new int[10];
//        for(int i = 0; i < 10; ++i)
//        {
//            _ptr[i] = d._ptr[i];
//        }
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//    Date& operator=(const Date& d)
//    {
//        if(this != &d)
//        {
//            for(int i = 0; i < 10; ++i)
//            {
//                _ptr[i] = d._ptr[i];
//            }
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//    ~Date()
//    {
//        delete _ptr;
//        cout << "~Date()" << endl;
//    }
//    void Print()
//    {
//        cout << _year << "年"  << _month << "月" << _day << "日" << endl;
//    }
//private:
//    A _aa;
//    int* _ptr;
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d1;
//    Date d2(d1);
//    Date d3 = d1;
//    d3 = d1;
//    d1.Print();
//    d2.Print();
//    d3.Print();
//    return 0;
//}


/********************************************************************************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int* a = new int[m];
        int* b = new int[m];
        int* min_cost = new int[m];
        for(int i = 0; i < m; ++i)
        {
            cin >> a[i] >> b[i];
        }
        for(int i = 0; i < m; ++i)
        {
            if(n % a[i] == 0)
            {
                min_cost[i] = (n / a[i]) * b[i];
            }
            else
            {
                min_cost[i] = (n / a[i] + 1) * b[i];
            }
        }
        sort(min_cost, min_cost + m);
        cout << min_cost[0] << endl;
    }
}
