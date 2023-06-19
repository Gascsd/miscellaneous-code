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
template<class K>
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
    
private:
    BucketHash::HashTable<K, K, SetKeyOfT> _ht;
};
}

