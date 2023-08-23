//
//  list.h
//  Test_8_23
//
//  Created by zht on 2023/8/23.
//

#ifndef list_h
#define list_h


namespace my
{
template<typename T>
struct ListNode
{
    T _val;
    ListNode* _next;
    ListNode* _prev;
    
    ListNode(T val)
    {
        _val = val;
        _next = nullptr;
        _prev = nullptr;
    }
};

template<typename T>
class list
{
public:
    list()
    {
        _head = new ListNode<T>(0);
        _head->_next = _head;
        _head->_prev = _head;
        _size = 0;
    }
    void push_back(T val)
    {
        ListNode<T>* newNode = new ListNode<T>(val);
        ListNode<T>* prev = _head->_prev;
        //链接
        prev->_next = newNode;
        newNode->_prev = prev;
        newNode->_next = _head;
        _head->_prev = newNode;
        _size++;
    }
    void pop_front()
    {
        if(!empty())
        {
            ListNode<T>* delNode = _head->_next;
            ListNode<T>* next = delNode->_next;
            //处理链接关系
            _head->_next = next;
            next->_prev = _head;
            
            delete delNode;
            --_size;
        }
    }
    bool empty()
    {
        return _size == 0;
    }
    int size()
    {
        return _size;
    }
    T front()
    {
        return _head->_next->_val;
    }
    T back()
    {
        return _head->_prev->val;
    }
private:
    ListNode<T>* _head;
    int _size;
};

}

#endif /* list_h */
