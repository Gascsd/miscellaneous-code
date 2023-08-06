//
//  string.hpp
//  Test_7_13
//
//  Created by zht on 2023/7/13.
//

#pragma once
#include <iostream>
using namespace std;
namespace  zht
{
class string
{
public:
    typedef char* iterator;
    iterator begin()
    {
        return _str;
    }
    iterator end()
    {
        return _str + _size;
    }
    string(const char* str = "")
        :_size(strlen(str))
        , _capacity(_size)
    {
        cout << "string(const char* str = "") -- 构造函数" << endl;
        _str = new char[_capacity + 1];
        strcpy(_str, str);
    }
    // s1.swap(s2)
    void swap(string& s)
    {
        std::swap(_str, s._str);
        std::swap(_size, s._size);
        std::swap(_capacity, s._capacity);
    }
    // 拷贝构造
    string(const string& s)
        :_str(nullptr)
    {
        cout << "string(const string& s) -- 深拷贝" << endl;
        _str = new char[s._capacity + 1];
        strcpy(_str, s._str);
        _size = s._size;
        _capacity = s._capacity;
         
//        string tmp(s._str);
//        swap(tmp);
    }
    // 赋值重载
    string& operator=(const string& s)
    {
        cout << "string& operator=(string s) -- 深拷贝" << endl;
        string tmp(s);
        swap(tmp);
        return *this;
    }
//    // 移动构造
//    string(string&& s)
//        :_str(nullptr)
//        ,_size(0)
//        ,_capacity(0)
//    {
//        cout << "string(string&& s) -- 移动语义" << endl; swap(s);
//    }
//    // 移动赋值
//    string& operator=(string&& s)
//    {
//        cout << "string& operator=(string&& s) -- 移动语义" << endl; swap(s);
//        return *this;
//    }
    ~string()
    {
        delete[] _str;
        _str = nullptr;
    }
    char& operator[](size_t pos)
    {
        assert(pos < _size);
        return _str[pos];
    }
    void reserve(size_t n)
    {
        if (n > _capacity)
        {
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }
    }
    void push_back(char ch)
    {
        if (_size >= _capacity)
        {
            size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
            reserve(newcapacity);
        }
        _str[_size] = ch;
        ++_size;
        _str[_size] = '\0';
    }
    //string operator+=(char ch)
    string& operator+=(char ch)
    {
        push_back(ch);
        return *this;
    }
    const char* c_str() const
    {
        return _str;
    }
    

private:
    char* _str;
    size_t _size;
    size_t _capacity; // 不包含最后做标识的\0
};
string to_string(int value)
{
    bool flag = true;
    if (value < 0)
    {
        flag = false;
        value = 0 - value;
    }
    string str;
    while (value > 0)
    {
        int x = value % 10;
        value /= 10;
        str += ('0' + x);
    }
    if (flag == false)
    {
        str += '-';
    }
    std::reverse(str.begin(), str.end());
    return str;
}
}


// 请模拟实现红黑树的插入--注意：为了后序封装map和set，本文在实现时给红黑树多增加了一个头结点
enum Color
{
    Red,
    Black
};
template<class T>
class RBTreeNode
{
    T _data;
    RBTreeNode* _parent;
    RBTreeNode* _left;
    RBTreeNode* _right;
    Color _color;
    RBTreeNode(T data)
        :_left(nullptr)
        ,_right(nullptr)
        ,_parent(nullptr)
        ,_color(Black)
    {}
};
template<class T>
class RBTree
{
    typedef RBTreeNode<T> Node;
public:
    RBTree()
    {
        _pHead = new Node;
        _pHead->_left = _pHead;
        _pHead->_right = _pHead;
    }

    // 在红黑树中插入值为data的节点，插入成功返回true，否则返回false
    // 注意：为了简单起见，本次实现红黑树不存储重复性元素
    bool Insert(const T& data)
    {
        
        if(data > _pHead->_parent->_data)
        {
            
        }
    }
    
    // 检测红黑树中是否存在值为data的节点，存在返回该节点的地址，否则返回nullptr
    Node* Find(const T& data);
    
    // 获取红黑树最左侧节点
    Node* LeftMost();
    
    // 获取红黑树最右侧节点
    Node* RightMost();
    
    // 检测红黑树是否为有效的红黑树，注意：其内部主要依靠_IsValidRBTRee函数检测
    bool IsValidRBTRee();
private:
    bool _IsValidRBTRee(Node* pRoot, size_t blackCount, size_t pathBlack);
    // 左单旋
    void RotateL(Node* pParent);
    // 右单旋
    void RotateR(Node* pParent);
    // 为了操作树简单起见：获取根节点
    Node*& GetRoot()
    {
        if(_pHead && _pHead->_parent)
        {
            return _pHead->_parent;
        }
        else
        {
            return nullptr;
        }
    }
private:
    Node* _pHead;
};
