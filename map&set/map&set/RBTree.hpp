//
//  RBTree.hpp
//  RBTree
//
//  Created by zht on 2023/5/14.
//

#pragma once
#include <iostream>
using namespace std;


enum Color
{
    RED,
    BLACK
};
//这里使用T来封装
template<class T>
struct RBTreeNode
{
    T _data;
    RBTreeNode* _left;
    RBTreeNode* _right;
    RBTreeNode* _parent;
    Color _col;
    RBTreeNode(const T data)
        :_data(data)
        ,_left(nullptr)
        ,_right(nullptr)
        ,_parent(nullptr)
        ,_col(RED)
    {}
};

template<class T, class Ref, class Ptr>
struct __RBTreeIterator
{
    typedef RBTreeNode<T> Node;
    typedef __RBTreeIterator<T, Ref, Ptr> Self;
    __RBTreeIterator(Node* node)
        :_node(node)
    {}
    __RBTreeIterator(const Self& s)
        :_node(s._node)
    {}
    Ref operator*()
    {
        return _node->_data;
    }
    Ptr operator->()
    {
        return &_node->_data;
    }
    Self& operator++()
    {
        
    }
    Self& operator--()
    {
        
    }
    Self operator++(int)
    {
        
    }
    Self operator--(int)
    {
        
    }
    bool operator==(const Self& s) const
    {
        return _node == s._node;
    }
    bool operator!=(const Self& s) const
    {
        return _node != s._node;
    }
    Node* _node;
};

template<class K, class T, class KeyOfT>
class RBTree
{
    typedef RBTreeNode<T> Node;
public:
    typedef 
    bool Insert(const T& data)
    {
        if(_root == nullptr)
        {
            _root = new Node(data);
            _root->_col = BLACK;
            return true;
        }
        KeyOfT kot;
        Node* cur = _root;
        Node* parent = nullptr;
        //找到插入位置
        while(cur)
        {
            if(kot(cur->_data) < kot(data.first))
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(kot(cur->_data) > kot(data.first))
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false;
            }
        }
        cur = new Node(data);
        cur->_col = RED;
        //连接上
        cur->_parent = parent;
        if(kot(parent->_kv) > kot(cur->_kv))
        {
            parent->_left = cur;
        }
        else
        {
            parent->_right = cur;
        }
        //判断颜色是否合法
        while(parent && cur->_parent->_col == RED)
        {
            Node* grandfather = parent->_parent;
            if(parent == grandfather->_left)//当parent是grandfather左节点
            {
                Node* uncle = grandfather->_right;
                //情况一：uncle存在且为红
                if(uncle && uncle->_col == RED)
                {
                    grandfather->_col = RED;
                    uncle->_col = parent->_col = BLACK;
                    
                    cur = grandfather;
                    parent = cur->_parent;
                }
                //出现下面的情况就说明树的结构出现问题，需要对结构进行调整（旋转）
                else//uncle不存，或者在且为黑
                {
                    //情况二：grandfather、parent、cur在一条直线上
                    if(parent->_left == cur)
                    {
                        RotateR(grandfather);
                        
                        grandfather->_col = RED;
                        parent->_col = BLACK;
                    }
                    //情况二：grandfather、parent、cur在一条折线上
                    else
                    {
                        RotateL(parent);
                        RotateR(grandfather);
                        
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    break;
                }
            }
            else//当parent是grandfather右节点
            {
                Node* uncle = grandfather->_left;
                //情况一：uncle存在且为红
                if(uncle && uncle->_col == RED)
                {
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;
                    
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else//uncle不存在，或者存在且为黑
                {
                    //情况二：grandfather、parent、cur在一条直线上
                    if(parent->_right == cur)
                    {
                        RotateL(grandfather);
                        
                        grandfather->_col = RED;
                        parent->_col = BLACK;
                    }
                    //情况二：grandfather、parent、cur在一条折线上
                    else
                    {
                        RotateR(parent);
                        RotateL(grandfather);
                        
                        grandfather->_col = RED;
                        cur->_col = BLACK;
                    }
                    break;
                }
            }
        }
        _root->_col = BLACK;
        return true;
    }
    void RotateL(Node* parent)//左单旋
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        Node* ppNode = parent->_parent;
        
        //处理subRL的部分
        parent->_right = subRL;
        if(subRL)
            subRL->_parent = parent;
        //处理parent和subR之间的关系
        subR->_left = parent;
        parent->_parent = subR;
        //处理subR的parent
        if(ppNode)//parent不是根节点的时候，需要处理parent的父亲节点
        {
            subR->_parent = ppNode;
            if(ppNode->_left == parent)//parent是左节点
            {
                ppNode->_left = subR;
            }
            else//parent是右节点
            {
                ppNode->_right = subR;
            }
        }
        else//parent是根节点的时候
        {
            _root = subR;
            subR->_parent = nullptr;
        }
    }
    void RotateR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        Node* ppNode = parent->_parent;
        
        if(subLR)
            subLR->_parent = parent;
        parent->_left = subLR;
        
        subL->_right = parent;
        parent->_parent = subL;
        if(ppNode)
        {
            subL->_parent = ppNode;
            if(ppNode->_left == parent)
                ppNode->_left = subL;
            else
                ppNode->_right = subL;
        }
        else
        {
            _root = subL;
            subL->_parent = nullptr;
        }
    }
private:
    Node* _root = nullptr;
};