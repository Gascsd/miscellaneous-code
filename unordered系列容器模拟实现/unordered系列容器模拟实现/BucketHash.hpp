#pragma once
#include <iostream>
#include <string>
#include <vector>
namespace my
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
template<class _K, class _T, class _KeyOfT, class _Hash = HashFunc<_K>>
class HashTable;//声明哈希表类
template<class K, class T, class KeyOfT, class Hash = HashFunc<K>>
struct __HTIterator
{
    typedef HashTable<K,  T, KeyOfT, Hash> HT;
    typedef __HTIterator<K,T,KeyOfT,Hash> Self;
    typedef HashNode<T> Node;
    
    Node* _node;
    HT* _ht;
    
    __HTIterator(Node* node, HT* ht)
        :_node(node)
        ,_ht(ht)
    {}
    
    T& operator*()
    {
        return _node->_data;
    }
    T* operator->()
    {
        return &_node->_data;
    }
    bool operator!=(const Self& s)
    {
        return _node != s._node;
    }
    bool operator== (const Self& s)
    {
        return _node==s._node;
    }
    Self& operator++()
    {
        if(_node->_next)//当前桶还有元素
        {
            _node = _node->_next;
        }
        else//当前桶走完了，找下一个桶
        {
            size_t hashi = Hash()(KeyOfT()(_node->_data)) % _ht->_tables.size();//找到当前桶的哈希地址
            //找到下一个有元素的哈希桶对应的哈希地址，并将其第一个元素赋值给node
            ++hashi;
            while(hashi < _ht->_tables.size())
            {
                if(_ht->_tables[hashi])
                {
                    _node = _ht->_tables[hashi];
                    break;
                }
                else
                {
                    ++hashi;
                }
            }
            //后面没有桶了
            if(hashi == _ht->_tables.size())
            _node = nullptr;
        }
        return *this;
    }
    Self operator++(int)
    {
        Self tmp = *this;
        operator++();
        return tmp;
    }
};
template<class K, class T, class KeyOfT, class Hash>
class HashTable
{
    typedef HashNode<T> Node;
    //由于在迭代器类中需要调用HashTable中的私有成员，所以这里给出友元
    template<class _K, class _T, class _KeyOfT, class _Hash>//由于在clang下，使用同一个模版参数名会出现报错：Declaration of '模版参数名' shadows template parameter，所以这里在迭代器类的模版参数前加上_以示区分
    friend struct __HTIterator;
    
public:
    typedef __HTIterator<K, T, KeyOfT, Hash> iterator;
    //迭代器
    iterator begin()
    {
        //遍历，找到第一个有元素的桶
        for(size_t i = 0; i < _tables.size(); ++i)
        {
            if(_tables[i])
            {
                return iterator(_tables[i], this);
            }
        }
        return iterator(nullptr, this);
    }
    iterator end()
    {
        return iterator(nullptr, this);
    }
    //默认成员函数
    HashTable()
        :_n(0)
    {
        _tables.resize(10);
    }
    ~HashTable()
    {
        //遍历整个哈希表，依次释放节点
        for(size_t i = 0; i < _tables.size(); ++i)
        {
            Node* cur = _tables[i];
            while(cur)
            {
                Node* next = cur->_next;
                delete cur;
                cur = next;
            }
            _tables[i] = nullptr;
        }
    }
    
    //其他接口
    std::pair<iterator, bool> Insert(const T& data)
    {
        iterator it = Find(KeyOfT()(data));
        if(it != end())
            return make_pair(it, false);
        if(_n == _tables.size())
        {
            std::vector<Node*> newTables;
            newTables.resize(2* _tables.size(), nullptr);
            for(size_t i = 0; i < _tables.size(); ++i)
            {
                Node* cur = _tables[i];
                while(cur)
                {
                    Node* next = cur->_next;
                    size_t hashi = Hash()(KeyOfT()(cur->_data)) % newTables.size();
                    cur->_next = newTables[hashi];
                    newTables[hashi] = cur;
                    cur = next;
                }
                _tables[i] = nullptr;
            }
            _tables.swap(newTables);
        }
        size_t hashi = Hash()(KeyOfT()(data)) % _tables.size();
        Node* newnode = new Node(data);
        newnode->_next = _tables[hashi];
        _tables[hashi] = newnode;
        ++_n;
        
        return make_pair(iterator(newnode, this), true);
    }
    
    iterator Find(const K& key)
    {
        size_t hashi = Hash()(key) % _tables.size();//找到key对应的哈希地址
        Node* cur = _tables[hashi];//遍历该地址对应的哈希桶
        while(cur)
        {
            if(KeyOfT()(cur->_data) == key)//找到了
            {
                return iterator(cur, this);
            }
            else//没找到
            {
                cur = cur->_next;
            }
        }
        return end();
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
