//
//  main.cpp
//  Test_5_13
//
//  Created by zht on 2023/5/13.
//



#include "TestMap.hpp"

void Test1()
{
    set<int> s1;//默认构造
    vector<int> v = {1,3,5,2,6,3,5,1};
    set<int> s2(v.begin(), v.end());//迭代器区间构造
    set<int> s3(s2);//拷贝构造
    cout << "s1:";
    for(auto e : s1)
    {
        cout << e << " ";
    }
    cout << endl;
    cout << "s2:";
    for(auto e : s2)
    {
        cout << e << " ";
    }
    cout << endl;
    cout << "s3:";
    for(auto e : s3)
    {
        cout << e << " ";
    }
    cout << endl;
}
void Test2()
{
    vector<int> v = {1,3,5,2,6,3,5,1};
    set<int> s(v.begin(), v.end());//使用set存放之后可以去重
    set<int>::iterator it1 = s.begin();
    cout << "正向迭代器：";
    while(it1 != s.end())
    {
        cout <<*it1 << " ";
        ++it1;
    }
    cout << endl;
    set<int>::reverse_iterator it2 = s.rbegin();
    cout << "反向迭代器：";
    while (it2 != s.rend())
    {
        cout << *it2 << " ";
        ++it2;
    }
    cout << endl;
}
void Test3()
{
    vector<int> v = {1,3,5,2,6,3,5,1};
    set<int> s(v.begin(), v.end());//使用set存放之后可以去重
    cout << "before insert:";
    auto it1 = s.begin();
    while(it1 != s.end())
    {
        cout <<*it1 << " ";
        ++it1;
    }
    cout << endl;
    //insert
    auto a1 = s.insert(4);
    auto a2 = s.insert(4);
    cout << "after insert:";
    it1 = s.begin();
    while(it1 != s.end())
    {
        cout <<*it1 << " ";
        ++it1;
    }
    cout << endl;
    cout << "a1:" << *(a1.first) << ":" << a1.second << endl;
    cout << "a2:" << *(a2.first) << ":" << a2.second << endl;
    cout << "---------------------------" << endl;
    s.erase(4);
    cout << "after erase";
    it1 = s.begin();
    while(it1 != s.end())
    {
        cout <<*it1 << " ";
        ++it1;
    }
    cout << endl;
}
void Test4()
{
    set<int> s;
    for(int i = 1; i < 10; ++i)
        s.insert(10 * i);
    auto it = s.find(30);
    if(it != s.end())
        s.erase(it);
    for(const auto& e : s)
    {
        cout << e << " ";
    }
    cout << endl;
    auto it1 = s.lower_bound(40);
    auto it2 = s.upper_bound(70);
    s.erase(it1,it2);
    for(const auto& e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}
void Test5()
{
    vector<int> v = {1,3,5,2,6,3,5,1};
    set<int> s(v.begin(), v.end());
    multiset<int> ms(v.begin(), v.end());
    cout << "     set:";
    for(const auto& e : s)
    {
        cout << e << " ";
    }
    cout << endl;
    cout << "multiset:";
    for(const auto& e : ms)
    {
        cout << e << " ";
    }
    cout << endl;
}
void Test6()
{
    vector<string> vs = {"apple", "banana", "apple","orange", "watermelon", "orange", "apple", "watermelon", "watermelon", "apple", "orange", "apple"};
    map<string,int> m1;//默认构造
    for(const auto& e : vs)//统计次数的方式
    {
        m1[e]++;
    }
    map<string,int> m2(m1.begin(), m1.end());//迭代器区间
    map<string,int> m3(m1);//拷贝构造
    m1 = m3;//赋值重载
    cout << "---------------m1---------------" << endl;
    for(const auto& e : m1)
    {
        cout << e.first << ":" << e.second << endl;
    }
    cout << "---------------m2---------------" << endl;
    for(const auto& e : m2)
    {
        cout << e.first << ":" << e.second << endl;
    }
    cout << "---------------m3---------------" << endl;
    for(const auto& e : m3)
    {
        cout << e.first << ":" << e.second << endl;
    }
}
void Test7()
{
    map<string, string> dict;
    dict.insert(make_pair("left", "左边"));
    dict.insert(make_pair("right", "右边"));
    dict.insert(make_pair("string", "字符串"));
    dict.insert(make_pair("sort", "排序"));
    for(const auto& e : dict)
    {
        cout << e.first << ":" << e.second << endl;
    }
    cout << "------after erase------" << endl;
    dict.erase("insert");
    for(const auto& e : dict)
    {
        cout << e.first << ":" << e.second << endl;
    }
    cout << "------after swap------" << endl;
    map<string, string> dict_swap;
    dict_swap.insert(make_pair("swap", "交换"));
    dict.swap(dict_swap);
    cout << "dict:" << endl;
    for(const auto& e : dict)
    {
        cout << e.first << ":" << e.second << endl;
    }
    cout << "dict_swap:" << endl;
    for(const auto& e : dict_swap)
    {
        cout << e.first << ":" << e.second << endl;
    }
    cout << "------after clear------" << endl;
    dict.clear();
    for(const auto& e : dict)
    {
        cout << e.first << ":" << e.second << endl;
    }
}

int main()
{
    Test7();
    return 0;
}
