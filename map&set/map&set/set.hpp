//
//  set.hpp
//  map&set
//
//  Created by zht on 2023/5/18.
//

#pragma once
#include "RBTree.hpp"

namespace zht
{
    template<class K>
    class set
    {
        struct SetKeyOfT
        {
            const K& operator()(const K& key)
            {
                return key;
            }
        };
        typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
        typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;
    public:
        iterator begin() const
        {
            return _t.begin();
        }
        iterator end() const
        {
            return _t.end();
        }
        pair<iterator, bool> insert(const K& key)
        {
            pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _t.Insert(key);
            return pair<iterator, bool>(ret.first, ret.second);
//            return _t.Insert(key);
        }
    private:
        RBTree<K, K, SetKeyOfT> _t;
    };
}

