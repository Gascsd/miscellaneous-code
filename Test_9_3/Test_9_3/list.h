//
//  list.h
//  Test_9_3
//
//  Created by zht on 2023/9/3.
//

#ifndef list_h
#define list_h

namespace my
{

template<class T>
struct listNode
{
    T _val;
    listNode* _prev;
    listNode* _next;
    
    listNode(T val = T())
        : _val(val)
        , _prev(nullptr)
        , _next(nullptr)
    {}
};


template<typename T>
class list
{
    typedef listNode<T> node;
public:
    list()
    {
        _head = new node();
        _size = 0;
    }
    void push_back(T val)
    {
        node* newNode = new node(val);
        node* tail = _head->_prev;
        //tail newnode  _head
        tail->_next = newNode;
        newNode->_prev = tail;
        _head->_prev = newNode;
        newNode->_next = _head;
        ++_size;
    }
    void pop_back()
    {
        node* delnode = _head->_prev;
        node* prev = delnode->_prev;
        prev->_next = _head;
        _head->_prev = prev;
        
        delete delnode;
        --_size;
    }
    size_t size()
    {
        return _size;
    }
private:
    node* _head;
    size_t _size;
};
}



#endif /* list_h */
