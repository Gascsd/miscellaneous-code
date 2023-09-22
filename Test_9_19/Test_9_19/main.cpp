//
//  main.cpp
//  Test_9_19
//
//  Created by zht on 2023/9/19.
//

#include <iostream>
using namespace std;
//设计一个类不能被拷贝
class NoCopy
{
public:
    NoCopy() {}
    NoCopy(const NoCopy& obj) = delete;
    NoCopy& operator=(const NoCopy& obj) = delete;
private:

};
//void test1()
//{
//    NoCopy obj1;
//    NoCopy obj2(obj1);
//}

//设计一个只能在堆上创建对象的类
class HeapOnly
{
public:
    static HeapOnly* CreateObj()
    {
        return new HeapOnly;
    }
private:
    HeapOnly() {}
    HeapOnly(const HeapOnly& obj) {};
};
//void test()
//{
//    HeapOnly* pobj =  HeapOnly::CreateObj();
//    HeapOnly obj2 = *pobj;
//}

//设计一个只能在栈上创建对象的类
//class StackOnly
//{
//public:
//    static StackOnly CreateObj()
//    {
//        cout << "StackOnly::CreateObj" << endl;
//        return StackOnly();
//    }
//    StackOnly(const StackOnly&) = delete;
//    //StackOnly(StackOnly&&) = delete;
//    StackOnly operator=(const StackOnly&) = delete;
//private:
//    StackOnly()
//    {}
//
//};
//void test()
//{
//    static StackOnly obj1 = StackOnly::CreateObj();
//}


class StackOnly
{
public:
    static StackOnly CreateObj()
    {
       return StackOnly();
    }
private:
     StackOnly(){}
     StackOnly(const StackOnly&) = delete;
};
void test2()
{
    static StackOnly obj = StackOnly::CreateObj();
}


int main()
{
    test2();
    return 0;
}
