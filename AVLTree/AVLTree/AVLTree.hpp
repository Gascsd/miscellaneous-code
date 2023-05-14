//
//  AVLTree.hpp
//  AVLTree
//
//  Created by zht on 2023/5/14.
//

#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
    pair<K,V> _kv;
    AVLTreeNode* _left;
    AVLTreeNode* _right;
    AVLTreeNode* _parent;
    int _bf;
    AVLTreeNode(const pair<K,V>& kv)
        :_kv(kv)
        ,_left(nullptr)
        ,_right(nullptr)
        ,_parent(nullptr)
        ,_bf(0)
    {}
};
template<class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K,V> Node;
public:
    AVLTree()
        :_root(nullptr)
    {}
    bool Insert(const pair<K,V>& kv)
    {
        if(_root == nullptr)//树为空的情况
        {
            _root = new Node(kv);
            return true;
        }
        //树不为空，找到插入位置
        Node* parent = nullptr;
        Node* cur = _root;
        while(cur)
        {
            if(cur->_kv.first < kv.first)//往右树走
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_kv.first > kv.first)//往左树走
            {
                parent = cur;
                cur = cur->_left;
            }
            else//有重复值，插入失败
                return false;
        }
        
        //走到需要插入的位置了，现在new一个节点插入
        cur = new Node(kv);
        //判断在左树还是右树
        if(parent->_kv.first < cur->_kv.first)//右边插入
        {
            parent->_right = cur;
            cur->_parent = parent;
        }
        else
        {
            parent->_left = cur;
            cur->_parent = parent;
        }
        
        //处理平衡因子
        while(parent)
        {
            //修改平衡因子
            if(cur == parent->_left)//在左树插入就--，右树就++
            {
                parent->_bf--;
            }
            else
            {
                parent->_bf++;
            }
            //判断是否合法，不合法就修改树的结构
            if(parent->_bf == 0)//刚好平衡，子树的高度没变，不需要修改父亲的平衡因子
                break;
            else if(parent->_bf == 1 || parent->_bf == -1)//子树高度改变，迭代修改父亲的平衡因子
            {
                cur = parent;
                parent = parent->_parent;
            }
            else if(parent->_bf == 2 || parent->_bf == -2)//结构不符合AVLTree，修改结构
            {
                //旋转
                if(parent->_bf == 2 && cur->_bf == 1)//左单旋
                {
                    RotateL(parent);
                }
                else if(parent->_bf == -2 && cur->_bf == -1)//右单旋
                {
                    RotateR(parent);
                }
                else if(parent->_bf == -2 && cur->_bf == 1)//左右双旋
                {
                    RotateLR(parent);
                }
                else if(parent->_bf == 2 && cur->_bf == -1)//右左双旋
                {
                    RotateRL(parent);
                }
                else
                {
                    assert(false);
                }
                break;
            }
            else//其他情况代表AVLTree实现出现问题
            {
                assert(false);
            }
        }
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
        //处理平衡因子
        parent->_bf = subR->_bf = 0;
    }

    void RotateR(Node* parent)//右单旋
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        Node* ppNode = parent->_parent;

        if(subLR)
            subLR->_parent = parent;
        parent->_left = subLR;

        parent->_parent = subL;
        subL->_right = parent;

        if(ppNode)
        {
            subL->_parent = ppNode;
            if(ppNode->_left == parent)
            {
                ppNode->_left = subL;
            }
            else
            {
                ppNode->_right = subL;
            }
        }
        else
        {
            _root = subL;
            subL->_parent = nullptr;
        }

        subL->_bf = parent->_bf = 0;
    }

    void RotateLR(Node* parent)//左右双旋
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf;
        //先对parent的left进行左单旋，得到中间过程
        RotateL(subL);
        //对中间过程的parent进行右单旋
        RotateR(parent);
        //现在树的结构已经平衡了，然后处理平衡因子
        //对于平衡因子的处理，这里只需要处理parent，subL和subLR，具体情况需要分插入的位置来决定
        if(bf == 0)//当subLR即是新插入的节点时
        {
            parent->_bf = subL->_bf = subLR->_bf = 0;
        }
        else if(bf == -1)//新插入的节点是subLR的左
        {
            subL->_bf = subL->_bf = 0;
            parent->_bf = 1;
        }
        else if(bf == 1)//新插入的节点是subLR的右
        {
            subL->_bf = -1;
            parent->_bf = subLR->_bf = 0;
        }
        else//出现意外情况
        {
            assert(false);
        }
    }

    void RotateRL(Node* parent)//右左双旋
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf;

        RotateR(subR);
        RotateL(parent);

        if(bf == 0)
        {
            parent->_bf = subR->_bf = subRL->_bf = 0;
        }
        else if(bf == 1)
        {
            subRL->_bf = subR->_bf = 0;
            parent->_bf = -1;
        }
        else if(bf == -1)
        {
            parent->_bf = subRL->_bf = 0;
            subR->_bf = 1;
        }
        else
        {
            assert(false);
        }
    }
    bool isBalance()
    {
        return isBalance(_root);
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
    int GetHeight(Node* root)
    {
        if(root == nullptr)
            return 0;
        int lh = GetHeight(root->_left);
        int rh = GetHeight(root->_right);
        return lh > rh ? lh + 1 : rh + 1;
    }
    bool isBalance(Node* root)
    {
        if(root == nullptr)
            return true;
        if(isBSTree(root))
        {
            int leftHeight = GetHeight(root->_left);
            int rightHeight = GetHeight(root->_right);
            
            return abs(leftHeight-rightHeight) < 2
                && isBalance(root->_left)
                && isBalance(root->_right);
        }
        else
            return false;
    }
private:
    Node* _root = nullptr;
};



