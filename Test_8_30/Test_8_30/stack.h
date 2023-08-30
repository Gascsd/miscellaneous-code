//
//  stack.h
//  Test_8_30
//
//  Created by zht on 2023/8/30.
//

#ifndef stack_h
#define stack_h


#include<vector>
#include<deque>

namespace my
{
template<class T, class Container = vector<T>>
class stack
{
public:
    void push(T val)
    {
        _con.push_back(val);
    }
    void pop()
    {
        _con.pop_back();
    }
    T top()
    {
        return _con.back();
    }
    bool empty()
    {
        return _con.empty();
    }
    size_t size()
    {
        cout << "this is my stack" << " ";
        return _con.size();
    }
private:
    Container _con;
};

template<class T, class Container = deque<T>>
class queue
{
public:
    void push(T val)
    {
        _con.push_back(val);
    }
    void pop()
    {
        _con.pop_front();
    }
    T front()
    {
        return _con.front();
    }
    T back()
    {
        return _con.back();
    }
    bool empty()
    {
        return _con.empty();
    }
    size_t size()
    {
        cout << "this is my queue" << " ";
        return _con.size();
    }
private:
    Container _con;
};
}


#endif /* stack_h */
