//
//  unordered_set.hpp
//  unordered系列容器模拟实现
//
//  Created by zht on 2023/6/19.
//

#pragma once
#include "BucketHash.hpp"

namespace zht
{
template<class K class Hash>
class unordered_set
{
    struct SetKeyOfT
    {
        const K operator()(const K& key)
        {
            return key;
        }
    };
public:
    typedef typename zht::BucketHash::HashTable<K, K, SetKeyOfT>::iteraotr iterator;
    iterator begin()
    {
        return _ht.begin();
    }
    iterator end()
    {
        return _ht.end();
    }
    
    std::pair<iterator,bool> insert(const K& key)
    {
        return _ht.Insert(key);
    }
    
private:
    BucketHash::HashTable<K, K, SetKeyOfT, Hash> _ht;
};
}

