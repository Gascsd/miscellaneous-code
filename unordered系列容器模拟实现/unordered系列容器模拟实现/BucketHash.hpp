//
//  BucketHash.hpp
//  unordered系列容器模拟实现
//
//  Created by zht on 2023/6/19.
//

#pragma once
#include <iostream>
#include <string>

namespace zht
{
namespace BucketHash
{
    template<class T>
    struct HashNode
    {
        T _data;
        HashNode* _next;
        
        HashNode(const T data)
            :_data(data)
            ,_next(nullptr)
        {}
    };
    template<class K>
    struct HashFunc
    {
        size_t operator()(const K& key)
        {
            return (size_t)key;
        }
    };
    template<>
    struct HashFunc<std::string>
    {
        size_t operator()(const std::string& key)
        {
            size_t hash = 0;
            for (auto ch : key)
            {
                hash *= 131;
                hash += ch;
            }
            return hash;
        }
    };
    template<class K, class T, class KeyOfT, class Hash = HashFunc<K>>
    class HashTable
    {
        typedef HashNode<T> Node;
    public:
        HashTable()
            :_n(0)
        {
            _tables.resize(10);
        }
        bool Insert(const T data)
        {
            if(Find(KeyOfT()(data)))
                return false;
            //扩容
            //负载因子为1的时候就扩容
            if(_n == _tables.size())
            {
                //扩容方式有两种，一种是遍历，然后创建新节点挂在新表上
                //由于方案一造成的消耗较大，所以这里就不实现了
//                HashTable<K, V, Hash> newTable;
//                newTable._tables.resize(2 * _tables.size());
                //另一种是直接更改节点的指向
                std::vector<Node*> newTables;
                newTables.resize(2* _tables.size(), nullptr);//这里暂时使用2倍的方式扩容
                for(size_t i = 0; i < _tables.size(); ++i)//遍历旧表，依次拿到每个桶的头节点
                {
                    Node* cur = _tables[i];
                    while(cur)
                    {
                        Node* next = cur->_next;//先使用一个指针保存next，以免更改cur指向之后找不到其他节点
                        size_t hashi = Hash()(cur->_kv.first) % newTables.size();//计算哈希位置
                        //头插到新表中
                        cur->_next = newTables[hashi];
                        newTables[hashi] = cur;
                        
                        cur = next;//迭代到next
                    }
                    _tables[i] = nullptr;//将旧表的内容置空，以免出现自动析构旧表的时候释放节点
                }
                _tables.swap(newTables);//交换旧表和新表
            }
            //插入
            size_t hashi = Hash()(KeyOfT()(data)) % _tables.size();//定址
            //头插
            Node* newnode = new Node(data);
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;
            ++_n;
            
            return true;
        }
        
        Node* Find(const K& key)
        {
            size_t hashi = Hash()(key) % _tables.size();//找到key对应的哈希地址
            Node* cur = _tables[hashi];//遍历该地址对应的哈希桶
            while(cur)
            {
                if(cur->_kv.first == key)//找到了
                {
                    return cur;
                }
                else//没找到
                {
                    cur = cur->_next;
                }
            }
            return nullptr;
        }
        bool Erase(const K& key)
        {
            size_t hashi = Hash()(key) % _tables.size();
            Node* prev = nullptr;//用prev存放当前节点的上一个节点，从而链接cur的前后节点
            Node* cur = _tables[hashi];
            while(cur)
            {
                if(cur->_kv.first == key)//找到了,准备删除
                {
                    if(_tables[hashi] == cur)//删除桶的头节点
                    {
                        _tables[hashi] = cur->_next;
                    }
                    else//删除非头节点
                    {
                        prev->_next = cur->_next;
                    }
                    
                    delete cur;
                    --_n;
                    return true;
                }
                else//没找到
                {
                    prev = cur;
                    cur = cur->_next;
                }
            }
            
            return false;
        }
        
    private:
        std::vector<Node*> _tables;//本质上是一个指针数组，存放节点指针。
        size_t _n = 0;
    };
}
}
