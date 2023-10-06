//
//  main.cpp
//  Test_10_4
//
//  Created by zht on 2023/10/4.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
using namespace std;

template<class T>
struct __tree_node__
{
    //构造函数
    __tree_node__(T& val = T())
        : _val(val)
        , _depth(-1)
        , _left(nullptr)
        , _right(nullptr)
        , _parent(nullptr)
    {}
    T _val;
    __tree_node__* _left;
    __tree_node__* _right;
    __tree_node__* _parent;
    int _depth;
};

template<class T>
class BSTree
{
    typedef __tree_node__<T> node;
public:
    BSTree() : _root(nullptr) {}//构造函数
    bool insert(T val)
    {
        node* parent = nullptr;
        node* cur = _root;
        while(cur != nullptr)
        {
            if(cur->_val == val)
            {
                return false;
            }
            else if(cur->_val > val)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                parent = cur;
                cur = cur->_right;
            }
        }
        node* tmp = new node(val);
        tmp->_depth = parent->_depth + 1;
        if(parent->_val > tmp->_val)
        {
            parent->_left = tmp;
            tmp->_parent = parent;
            return true;
        }
        else if(parent->_val < tmp->_val)
        {
            parent->_right = tmp;
            tmp->_parent = parent;
            return true;
        }
        else
        {
            //cout << "出现未知错误" << endl;
            return false;
        }
    }
private:
    node* _root;
};


int main()
{
    //forward_list
//    vector<int> v = {1,2,3,4,5};
//    list<int> lt = {2,3,4,5,6};
//    priority_queue<int> pq;
//    queue<int> q;
//    stack<int> st;
//    pq.push(1);
//    q.push(1);
//    st.push(1);
//    
//    map<string, int> mp;
//    mp.insert({"sort", 1});
//    mp.insert(make_pair("string", 1));
//    auto it = lt.begin();
//    while(it != lt.end())
//    {
//        cout << *it << " ";
//        ++it;
//    }
//    cout << endl;
    
    int arr[10] = { 0 };
    5[arr] = 5;
    //arr[5] <==> 5[arr] <==> *(arr + 5)
    
    for(auto& e : arr)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
