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

template<class K, class V>
struct RBTreeNode
{
    pair<K,V> _kv;
    RBTreeNode* _left;
    RBTreeNode* _right;
    RBTreeNode* _parent;
    Color _col;
    RBTreeNode(pair<K,V> kv)
        :_kv(_kv)
        ,_left(nullptr)
        ,_right(nullptr)
        ,_col(RED)
    {}
};

template<class K, class V>
class RBTree
{
    typedef RBTreeNode<K, V> Node;
public:
    bool Insert(pair<K,V>& kv)
    {
        if(_root == nullptr)
        {
            _root = new Node(kv);
            _root->_col = BLACK;
            return true;
        }
        Node* cur = _root;
        Node* parent = nullptr;
        //找到插入位置
        while(cur)
        {
            if(cur->_kv.first < kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_kv.first < kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false;
            }
        }
        cur = new Node(kv);
        cur->col = RED;
        //连接上
        cur->_parent = parent;
        if(parent->_kv.first > cur->_kv.first)
        {
            parent->_left = cur;
        }
        else
        {
            parent->_right = cur;
        }
        //判断颜色是否合法
        while(cur->_parent->col == RED)
        {
            Node* grandfather = parent->_parent;
            if(parent == grandfather->_left)//当parent是grandfather左节点
            {
                Node* uncle = grandfather->_right;
                //情况一：uncle存在且为红
                if(uncle && uncle->_col == RED)
                {
                    grandfather->_col = RED;
                    uncle->col = parent->_col = BLACK;
                    
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
                if(uncle && uncle->col == RED)
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
        _root->col = BLACK;
        return true;
    }
    void RotateL(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        Node* ppNdoe = parent->_parent;
        
        //首先处理subLR
        subLR->_parent = parent;
        parent->_left = subLR;
        
    }
    void RotateR(Node* parent)
    {
        
    }
private:
    Node* _root;
};
