//
//  unordered_map.hpp
//  unordered系列容器模拟实现
//
//  Created by zht on 2023/6/19.
//

#pragma once
#include "BucketHash.hpp"

namespace zht
{
template<class K, class V>
class unordered_map
{
    struct MapKeyOfT
    {
        const K operator()()
        {
            
        }
    };
public:
    
private:
    BucketHash::HashTable<K, std::pair<const K, V>, MapKeyOfT> _ht;
};
}
