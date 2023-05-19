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
            K& operator()(const pair<const K, V>& kv)
            {
                return kv.first;
            }
        };
    public:
        
    private:
        RBTree<K, pair<const K, V>, MapKeyOfT> _t;
    };
};
