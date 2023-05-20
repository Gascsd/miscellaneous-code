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
        
        bool insert(const K& key)
        {
            return _t.Insert(key);
        }
    private:
        RBTree<K, K, SetKeyOfT> _t;
    };
}

