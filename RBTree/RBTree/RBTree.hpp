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
    RBTreeNode(const pair<K,V> kv)
        :_kv(kv)
        ,_left(nullptr)
        ,_right(nullptr)
        ,_parent(nullptr)
        ,_col(RED)
    {}
};

template<class K, class V>
class RBTree
{
    typedef RBTreeNode<K, V> Node;
public:
    bool Insert(const pair<K,V>& kv)
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
        cur->_col = RED;
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
    void InOrder(vector<pair<K,V>>& v, Node* root)
    {
        if(root == nullptr)
            return;
        InOrder(v, root->_left);
        v.push_back(root->_kv);
        InOrder(v, root->_right);
    }
    bool isBSTree(Node* root)
    {
        vector<pair<K,V>> v;
        InOrder(v,root);
        for(size_t i = 0; i < v.size() - 1; ++i)
        {
            if(v[i].first > v[i+1].first)
                return false;
        }
        return true;
    }
    bool Check(Node* root, int blackNum, int ref)
    {
        if(root == nullptr)
        {
            if(blackNum != ref)
            {
                cout << "count of black is error" << endl;
                return false;
            }
            return true;
        }
        
        if(root->_col == RED && root->_parent->_col == RED)
        {
            cout << "more red node" << endl;
            return false;
        }
        if(root->_col == BLACK)
            ++blackNum;
        
        return Check(root->_left, blackNum, ref)
            && Check(root->_right, blackNum, ref);
    }
    bool isRBTree()
    {
        if(_root == nullptr)
            return true;
        if(isBSTree(_root))
        {
            if(_root->_col != BLACK)//判断性质2
                return false;
            int ref = 0;
            Node* left = _root;
            while(left)
            {
                if(left->_col == BLACK)
                    ++ref;
                left = left->_left;
            }
            
            return Check(_root, 0, ref);
        }
        else
            return false;
    }
private:
    Node* _root = nullptr;
};
