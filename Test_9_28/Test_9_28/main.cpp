//
//  main.cpp
//  Test_9_28
//
//  Created by zht on 2023/9/28.
//

#include <iostream>
using namespace std;

void test1()
{
    double d = 12.34;
    int a = static_cast<int>(d);
    int b = d;
    cout<< a << " " << b <<endl;
}
void test2()
{
    int a = 12;
    //int* p = static_cast<int*>(a);//这里使用static_cast就会报错
    int* p = reinterpret_cast<int*>(a);
    cout << p << endl;
}
void test3()
{
    volatile const int a = 10;
    //const int a = 10;
    //a = 20;//这里由于a是const修饰的变量，所以不能修改
    int* p = const_cast<int*>(&a);
    *p = 20;
    cout << a << " " << *p << endl;
}


class A
{
public:
    virtual void f() {}
    
    int _a = 1;
};
class B : public A
{
public:
    void f() {}
    int _b = 2;
};
void func(A* ptr)
{
    //B* bptr = (B*)ptr;
    B* bptr = dynamic_cast<B*>(ptr);
    if(bptr == nullptr)
    {
        cout << "类型转换错误：出现向下转换" << endl;
        return;
    }
    cout << bptr->_b << endl;
    cout << bptr->_a << endl;
}
void test4()
{
    A aa;
    B bb;
    func(&aa);
    func(&bb);
}
int main()
{
    test4();
    return 0;
}
