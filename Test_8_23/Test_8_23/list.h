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
    void push_front(T val)
    {
        ListNode<T>* newNode = new ListNode<T>(val);
        ListNode<T>* next = _head->_next;
        // _head <=> newNode <=> next
        _head->_next = newNode;
        newNode->_prev = _head;
        newNode->_next = next;
        next->_prev = newNode;
        ++_size;
    }
    void pop_back()
    {
        if(!empty())
        {
            ListNode<T>* delNode = _head->_prev;
            ListNode<T>* prev = delNode->_prev;
            
            _head->_prev = prev;
            prev->_next = _head;
            delete delNode;
            --_size;
        }
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
        if(!empty())
            return _head->_next->_val;
        else return 0;
    }
    T back()
    {
        if(!empty())
            return _head->_prev->_val;
        else return 0;
    }
private:
    ListNode<T>* _head;
    int _size;
};

void test_list_pop_back()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    int n = 4;
    while(n--)
    {
        std::cout << lt.back() << " ";
        lt.pop_back();
    }
    lt.pop_back();
    std::cout << lt.back() << " ";
}

}

#endif /* list_h */
