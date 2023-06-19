//
//  main.cpp
//  unordered系列容器模拟实现
//
//  Created by zht on 2023/6/19.
//

#include <iostream>
#include <vector>
#include "unordered_map.hpp"
#include "unordered_set.hpp"
using namespace std;

int main()
{
    zht::unordered_map<string, int> umap;
    //umap.insert(make_pair("string", 1));
    vector<string> vs = {"string", "string", "insert"};
    for(auto& str : vs)
    {
        umap[str]++;
    }
    zht::unordered_map<string, int>::iterator it = umap.begin();
    while(it != umap.end())
    {
        cout << it->first << ":" << it->second << endl;
        ++it;
    }
//    for(auto& e : umap)
//    {
//        cout << e.first << ":" << e.second << endl;
//    }
    return 0;
}
