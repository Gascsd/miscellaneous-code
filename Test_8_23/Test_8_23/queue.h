//
//  queue.h
//  Test_8_23
//
//  Created by zht on 2023/8/23.
//

#ifndef queue_h
#define queue_h

#include <list>
#include "list.h"
namespace my
{

template<typename T>
class queue
{
public:
    void push(T val)
    {
        _lt.push_back(val);
    }
    void pop()
    {
        _lt.pop_front();
    }
    bool empty()
    {
        return _lt.empty();
    }
    T front()
    {
        return _lt.front();
    }
    T back()
    {
        return _lt.back();
    }
    int size()
    {
        return _lt.size();
    }
private:
    my::list<T> _lt;
};


}



#endif /* queue_h */
