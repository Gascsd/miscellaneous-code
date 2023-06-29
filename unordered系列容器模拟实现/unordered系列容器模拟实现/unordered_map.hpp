//
//  unordered_map.hpp
//  unordered系列容器模拟实现
//
//  Created by zht on 2023/6/19.
//

#pragma once
#include "BucketHash.hpp"

namespace my
{
template<class K, class V, class Hash>
class unordered_map
{
    struct MapKeyOfT
    {
        const K operator()(const std::pair<const K,V>& kv)
        {
            return kv.first;
        }
    };
public:
    typedef typename my::BucketHash::HashTable<K, std::pair<const K, V>, MapKeyOfT>::iterator iterator;
    
    //迭代器
    iterator begin()
    {
        return _ht.begin();
    }
    iterator end()
    {
        return _ht.end();
    }
    std::pair<iterator, bool> insert(const std::pair<K, V>& data)
    {
        return _ht.Insert(data);
    }
    
    V& operator[](const K& key)
    {
        //return _ht.Insert(make_pair(key, V())).first->second;
        std::pair<iterator,bool> ret = _ht.Insert(make_pair(key, V()));
        return ret.first->second;
    }
    
private:
    BucketHash::HashTable<K, std::pair<const K, V>, MapKeyOfT, Hash> _ht;
};
}
