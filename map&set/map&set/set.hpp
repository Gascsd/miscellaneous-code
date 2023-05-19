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
            K& operator()(const K& key)
            {
                return key;
            }
        };
    public:
        
    private:
        RBTree<K, K, SetKeyOfT> _t;
    };
}

