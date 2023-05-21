//
//  map.hpp
//  map&set
//
//  Created by zht on 2023/5/18.
//

#pragma once
#include "RBTree.hpp"

namespace zht
{
    template<class K, class V>
    class map
    {
        struct MapKeyOfT
        {
            const K& operator()(const pair<const K, V>& kv)
            {
                return kv.first;
            }
        };
        typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
        typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;
    public:
        iterator begin()
        {
            return _t.begin();
        }
        iterator end()
        {
            return _t.end();
        }
        const_iterator begin() const
        {
            return _t.begin();
        }
        const_iterator end() const
        {
            return _t.end();
        }
        
        pair<iterator, bool> insert(const pair<const K, V>& kv)
        {
            return _t.Insert(kv);
        }
        V& operator[](const K& key)
        {
            pair<iterator, bool> ret = insert(make_pair(key, V()));
            return ret.first->second;
        }
    private:
        RBTree<K, pair<const K, V>, MapKeyOfT> _t;
    };
};
