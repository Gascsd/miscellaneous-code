//
//  CloseHash.hpp
//  Hash
//
//  Created by zht on 2023/5/22.
//
//闭散列哈希表的实现
#pragma once
#include <iostream>
#include <vector>
#include <string>
namespace zht
{
    enum State
    {
        EMPTY,
        EXIST,
        DELETE
    };

    template<class K, class V>//HashData数据结构体
    struct HashData
    {
        std::pair<K, V> _kv;
        State _state = EMPTY;
    };

    template<class K>//仿函数，映射到整型
    struct HashFunc
    {
        size_t operator()(const K& key)
        {
            return (size_t)key;
        }
    };
    template<>//模版特化
    struct HashFunc<std::string>
    {
        size_t operator()(const std::string& key)
        {
            //采用了特殊方法把各元素的值放在一起
            size_t hash = 0;
            for (auto ch : key)
            {
                hash *= 131;
                hash += ch;
            }
            return hash;
        }
    };

    template<class K, class V, class Hash = HashFunc<K>>
    class HashTable
    {
        typedef HashData<K, V> Data;
    public:
        //构造函数
        HashTable()
            :_n(0)
        {
            _tables.resize(10);
        }
        //插入
        bool Insert(const std::pair<K,V>& kv)
        {
            if(Find(kv.first))//如果已经存在，插入失败返回false
                return false;
            //扩容:判断是否扩容的方式是判断负载因子大小
            if(_n * 10 / _tables.size() >= 7)//负载因子大于0.7时扩容
            {
                HashTable<K, V, Hash> newTable;
                newTable._tables.resize(2 * _tables.size());//重新创建一个哈希表，大小是原表的二倍
                for(auto& e : _tables)//遍历原表，如果有数据的话就在新表中插入
                {
                    if(e._state == EXIST)
                    {
                        newTable.Insert(e._kv);
                    }
                }
                _tables.swap(newTable._tables);//交换二者的表（vector对象），这里调用的是vecotr库里的swap
            }
            
            //插入数据
            size_t hashi = Hash()(kv.first) % _tables.size();//通过Hash的匿名对象映射出一个整形，通过这个整型除留余数从而定址
            while(_tables[hashi]._state == EXIST)//映射的位置已经有值，出现哈希冲突，进行线性探测
            {
                ++hashi;
                hashi %= _tables.size();//++之后可能大于size，所以需要 模等一下
            }
            
            _tables[hashi]._kv = kv;
            _tables[hashi]._state = EXIST;
            ++_n;
            return true;
        }
        //查找
        Data* Find(const K& key)
        {
            //按照哈希函数的方式计算，得到哈希地址
            size_t hashi = Hash()(key) % _tables.size();
            //从该地址向后寻找，由于线性探测的问题，所以该地址不一定是实际存放要找的位置的值，所以需要继续向后找，直到遇到EMPTY为止
            while(_tables[hashi]._state != EMPTY)
            {
                if(_tables[hashi]._state == EXIST && _tables[hashi]._kv.first == key)
                    return &_tables[hashi];//找到了返回地址
                else//否则++hashi继续寻找
                {
                    ++hashi;
                    hashi %= _tables.size();
                }
            }
            return nullptr;//最终遇到EMPTY都没找到，返回空指针
        }
        //删除
        bool Erase(const K& key)
        {
            //由于直接删除该位置的值会引发后面的值的映射错误（会导致在找的时候提前找到空，所以不能直接删除，要使用伪删除法删除，即给一个DELETE状态）
            Data* ret = Find(key);
            if(ret)//找到值
            {
                //将该位置的值状态置为DELETE，然后n--
                ret->_state = DELETE;
                --_n;
                return true;//返回true表示删除成功
            }
            else//哈希表中没有该值，返回false
            {
                return false;
            }
        }
    private:
        std::vector<Data> _tables;//表里面存储的是HashData，HashData内部是一个KV结构和一个状态
        size_t _n = 0;//存储表中的有效数据个数
    };

using namespace std;
    //测试代码
    void TestHT1()
    {
        HashTable<int, int> ht;
        int a[] = { 18, 8, 7, 27, 57, 3, 38, 18 };
        for (auto e : a)
        {
            ht.Insert(make_pair(e, e));
        }

        ht.Insert(make_pair(17, 17));
        ht.Insert(make_pair(5, 5));

        cout << ht.Find(7) << endl;
        cout << ht.Find(8) << endl;

        ht.Erase(7);
        cout << ht.Find(7) << endl;
        cout << ht.Find(8) << endl;
    }

    void TestHT2()
    {
        string arr[] = { "苹果", "西瓜", "香蕉", "草莓", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
        //HashTable<string, int, HashFuncString> countHT;
        HashTable<string, int> countHT;
        for (auto& e : arr)
        {
            HashData<string, int>* ret = countHT.Find(e);
            if (ret)
            {
                ret->_kv.second++;
            }
            else
            {
                countHT.Insert(make_pair(e, 1));
            }
        }

        HashFunc<string> hf;
        cout << hf("abc") << endl;
        cout << hf("bac") << endl;
        cout << hf("cba") << endl;
        cout << hf("aad") << endl;
    }
}


