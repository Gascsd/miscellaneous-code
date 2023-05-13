//
//  main.cpp
//  Test_5_12
//
//  Created by zht on 2023/5/12.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
//int main()
//{
//    set<int> myset;
//    for(int i = 1; i < 10; ++i)
//        myset.insert(10 * i);
//    set<int>::iterator itlow = myset.lower_bound(30);
//    set<int>::iterator itup = myset.upper_bound(60);
//    myset.erase(itlow, itup);
//    auto begin = myset.begin();
//    while(begin != myset.end())
//    {
//        cout << *begin <<" ";
//        ++begin;
//    }
//    cout << endl;
//    return 0;
//}

int main()
{
    string arr[] = {"苹果","香蕉", "西瓜", "草莓","草莓","西瓜","西瓜","香蕉","苹果","苹果","苹果"};
    map<string, int> count_map;
    for(const auto& str : arr)
    {
        auto it = count_map.find(str);
        if(it == count_map.end())
        {
            count_map.insert(make_pair(str, 1));
        }
        else
        {
            it->second++;
        }
    }
    for(const auto& e : count_map)
    {
        cout << e.first << ":" << e.second << endl;
    }
    cout << "---------------------" <<endl;
    map<string,int> countMap;
    for(auto& e : arr)
    {
        countMap[e]++;
    }
    for(const auto& e : countMap)
    {
        cout << e.first << ":" << e.second << endl;
    }
    return 0;
}
