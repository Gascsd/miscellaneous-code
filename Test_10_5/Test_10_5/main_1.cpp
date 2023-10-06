//
//  main_1.cpp
//  Test_10_5
//
//  Created by zht on 2023/10/5.
//

#include <iostream>
#include <vector>
#include "vector.h"
using namespace std;

int test21()
{
    vector<int>array;//创建（实例化）一个vector<int>类型的对象array
    //尾插元素
    array.push_back(100);
    array.push_back(300);
    array.push_back(300);
    array.push_back(300);
    array.push_back(300);
    array.push_back(500);
    //array [100, 300, 300, 300, 300, 500]
    vector<int>::iterator itor;//定义一个迭代器itor
    //遍历array，删除所有的300
    for(itor = array.begin(); itor!=array.end(); itor++)
    {
        if(*itor == 300)//删除300
        {
            itor = array.erase(itor);//迭代器失效（后面会讲）
        }
    }
    //[100, 300, 300, 500]
    for(itor = array.begin(); itor != array.end(); itor++)
    {
        cout<< *itor << " ";
    }
    return 0;
}
void test22()
{
    int ar[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(ar) / sizeof(int);
    vector<int> v(ar, ar+n);
    cout << v.size() << ":" << v.capacity() << endl;//16
    v.reserve(100);//capacity
    v.resize(20);//size
    cout<< v.size() << ":" << v.capacity() << endl;
    v.reserve(50);
    v.resize(5);
    cout << v.size() << ":" << v.capacity() << endl;
}
void test23()
{
    vector<int> v(5,1);
    v.clear();
    for(auto& e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}
void test24()
{
    my::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
//    for(int i = 0; i < v.size(); ++i)
//    {
//        cout << v[i] << " ";
//    }
    auto it = v.begin();
    while(it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    auto pos = v.find(5);
    v.insert(pos, 50);
    it = v.begin();
    while(it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}


int main_1()
{
    test24();
    return 0;
}
