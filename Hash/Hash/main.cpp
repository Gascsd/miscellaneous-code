//
//  main.cpp
//  Hash
//
//  Created by zht on 2023/5/22.
//

#include <iostream>
#include "CloseHash.hpp"
#include "BucketHash.hpp"
using namespace std;

void TestHT1()
{
    zht::BucketHash::HashTable<int, int> ht;
    int a[] = { 18, 8, 7, 27, 57, 3, 38, 18 };
    for (auto e : a)
    {
        ht.Insert(make_pair(e, e));
    }

    ht.Insert(make_pair(17, 17));
    ht.Insert(make_pair(5, 5));

    cout << ht.Find(7) << endl;
    cout << ht.Find(8) << endl;

    ht.Erase(7);
    cout << ht.Find(7) << endl;
    cout << ht.Find(8) << endl;
}

void TestHT2()
{
    string arr[] = { "苹果", "西瓜", "香蕉", "草莓", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
    //HashTable<string, int, HashFuncString> countHT;
    zht::BucketHash::HashTable<string, int> countHT;
    for (auto& e : arr)
    {
        auto ret = countHT.Find(e);
        if (ret)
        {
            ret->_kv.second++;
        }
        else
        {
            countHT.Insert(make_pair(e, 1));
        }
    }

    
}
int main()
{
    TestHT1();
    TestHT2();
    return 0;
}
