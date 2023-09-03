//
//  stack_queue.h
//  Test_9_3
//
//  Created by zht on 2023/9/3.
//

#ifndef stack_queue_h
#define stack_queue_h


namespace my
{
template<class T, class Container = list<T>>
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
    size_t size()
    {
        return _con.size();
    }
    bool empty()
    {
        return _con.empty();
    }
    T& top()
    {
        return _con.back();
    }
private:
    Container _con;
};


template<class T, class Container = list<T>>
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
    size_t size()
    {
        return _con.size();
    }
    bool empty()
    {
        return _con.empty();
    }
    T& front()
    {
        return _con.front();
    }
    T& back()
    {
        return _con.back();
    }
private:
    Container _con;
};
template<class T>
struct Com
{
    bool operator()(T e1, T e2)
    {
        return e1 < e2;
    }
};

template<class T, class Container = std::list<T>, class Compare = std::less<T>>
class priority_queue
{
public:
    void push(T val)
    {
        
    }
    void pop()
    {
        
    }
    T& top()
    {

    }
    size_t size()
    {
        return _con.size();
    }
    bool empty()
    {
        return _con.empty();
    }

private:
    Container _con;
};
}

#endif /* stack_queue_h */
