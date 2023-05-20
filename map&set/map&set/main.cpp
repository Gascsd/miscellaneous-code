//
//  main.cpp
//  map&set
//
//  Created by zht on 2023/5/18.
//

#include <iostream>
#include "map.hpp"
#include "set.hpp"


void TestInsert()
{
    zht::map<int, int> m;
    zht::set<int> s;
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
    for(auto e : a)
    {
        m.insert(make_pair(e, e));
        s.insert(e);
    }
//    for(auto e : m)
//    {
//        cout << e.first << ":" << e.second << endl;
//    }
//    cout << endl;
//    for(auto e : s)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
}

int main()
{
    TestInsert();
    return 0;
}
