//
//  main.cpp
//  map&set
//
//  Created by zht on 2023/5/18.
//

#include <iostream>
#include <string>
#include <set>
#include "map.hpp"
#include "set.hpp"

void TestInsert()
{
    zht::map<int, int> m;
    zht::set<int> s;
    set<int> s_stl;
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
    for(auto e : a)
    {
        m.insert(make_pair(e, e));
        s.insert(e);
        s_stl.insert(e);
    }
//    for(auto e : m)
//    {
//        //e.first++;
//        e.second++;
//        cout << e.first << ":" << e.second << endl;
//    }
//    cout << endl;
    for(auto e : s)
    {
        e++;
        cout << e << " ";
    }
    cout << endl;
//    for(auto e& : s_stl)
//    {
//        e++;
//        cout << e << " ";
//    }
    cout << endl;
}
void Test2()
{
    zht::map<string, int> countMap;
    string arr[] = {"apple", "apple", "apple", "banana", "banana", "orange", "prange"};
    for(auto& e : arr)
    {
        countMap[e]++;
    }
    for(auto& e : countMap)
    {
        cout << e.first << ":" << e.second << endl;
    }
}
void Test()
{
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
    set<int> s;
    for(auto& e : a)
    {
        s.insert(e);
    }
    for(auto& e : s)
    {
        //e++;
        cout << e << " ";
    }
    cout << endl;
}
int main()
{
//    Test();
    TestInsert();
//    Test2();
    return 0;
}
