//
//  main.cpp
//  Test_10_3
//
//  Created by zht on 2023/10/3.
//

#include <iostream>
#include <vector>

//using namespace std;
#define N 10

//class SeqListStatic
//{
//public:
//    SeqListStatic()
//    {
//        _arr = new int[N];
//        _size = 0;
//    }
//    ~SeqListStatic()
//    {
//        delete[] _arr;
//        _arr = nullptr;
//        _size = 0;
//    }
//    SeqListStatic(const SeqListStatic& obj)
//    {
//        _arr = new int[N];
//        for(int i = 0; i < N; ++i)
//        {
//            _arr[i] = obj._arr[i];
//        }
//        _size = obj._size;
//    }
//    void swap(SeqListStatic& obj)
//    {
//        std::swap(_arr, obj._arr);
//        std::swap(_size, obj._size);
//    }
//    SeqListStatic& operator=(SeqListStatic tmp)//现代写法
//    {
//        swap(tmp);
//        return *this;
//    }
//    bool push_back(int val)//尾插
//    {
//        if(_size < 10)
//        {
//            _arr[_size++] = val;
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    void pop_back()
//    {
//        if(_size != 0)
//            --_size;
//    }
//    bool push_front(int val)
//    {
//        if(_size == 10)
//        {
//            return false;
//        }
//        else
//        {
//            for(int i = _size; i > 0; --i)
//            {
//                _arr[i] = _arr[i - 1];
//            }
//            _arr[0] = val;
//            ++_size;
//            return true;
//        }
//    }
//    void pop_front()
//    {
//        for(int i = 0; i < _size - 1; ++i)
//        {
//            _arr[i] = _arr[i + 1];
//        }
//        --_size;
//    }
//    void Print()
//    {
//        for(int i = 0; i < _size; ++i)
//        {
//            std::cout << _arr[i] << " ";
//        }
//        std::cout << std::endl;
//    }
//    bool insert(int pos, int val)//在pos位置插入
//    {
//        if(_size < 10)
//        {
//            for(int i = _size; i > pos; --i)
//            {
//                _arr[i] = _arr[i - 1];
//            }
//            _arr[pos] = val;
//            ++_size;
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    void erase(int pos)//删除pos位置的元素
//    {
//        if(_size > 0)
//        {
//            for(int i = pos; i < _size - 1; ++i)
//            {
//                _arr[i] = _arr[i + 1];
//            }
//            --_size;
//        }
//    }
//    int find(int val)
//    {
//        for(int i = 0; i < _size; ++i)
//        {
//            if(_arr[i] == val)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//private:
//    int* _arr;
//    int _size;//保存的有效元素个数
//};
//
//
//
//
//
//class SeqList
//{
//public:
//    SeqList()
//    //初始化列表
//        :_arr(nullptr)
//        , _size(0)
//        , _capacity(0)
//    {
//        reserve();
//    }
//    ~SeqList()
//    {
//        delete[] _arr;
//        _arr = nullptr;
//        _capacity = _size = 0;
//    }
//    SeqList(const SeqList& obj)
//    {
//        _arr = new int[obj._capacity];
//        for(int i = 0; i < _size; ++i)
//        {
//            _arr[i] = obj._arr[i];
//        }
//        _size = obj._size;
//        _capacity = obj._capacity;
//    }
//    void swap(SeqList& obj)
//    {
//        std::swap(_arr, obj._arr);
//        std::swap(_size, obj._size);
//    }
//    SeqList& operator=(SeqList tmp)//现代写法
//    {
//        swap(tmp);
//        return *this;
//    }
//    /**********************************************************************************/
//    //增删查改
//
//    void push_back(int val)//尾插
//    {
//        if(_size == _capacity)//空间不够
//        {
//            //扩容
//            reserve();
//        }
//        _arr[_size++] = val;
//    }
//    void pop_back()
//    {
//        if(_size != 0)
//            --_size;
//    }
//    void push_front(int val)
//    {
//        if(_size == _capacity)
//        {
//            reserve();
//        }
//        else
//        {
//            for(int i = _size; i > 0; --i)
//            {
//                _arr[i] = _arr[i - 1];
//            }
//            _arr[0] = val;
//            ++_size;
//        }
//    }
//    void pop_front()
//    {
//        for(int i = 0; i < _size - 1; ++i)
//        {
//            _arr[i] = _arr[i + 1];
//        }
//        --_size;
//    }
//    void Print()
//    {
//        for(int i = 0; i < _size; ++i)
//        {
//            std::cout << _arr[i] << " ";
//        }
//        std::cout << std::endl;
//    }
//    void insert(int pos, int val)//在pos位置插入
//    {
//        if(_size == _capacity)
//        {
//            reserve();
//        }
//        for(int i = _size; i > pos; --i)
//        {
//            _arr[i] = _arr[i - 1];
//        }
//        _arr[pos] = val;
//        ++_size;
//    }
//    void erase(int pos)//删除pos位置的元素
//    {
//        if(_size > 0)
//        {
//            for(int i = pos; i < _size - 1; ++i)
//            {
//                _arr[i] = _arr[i + 1];
//            }
//            --_size;
//        }
//    }
//    int find(int val)
//    {
//        for(int i = 0; i < _size; ++i)
//        {
//            if(_arr[i] == val)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//private:
//    void reserve()
//    {
//        int newCapacity = _capacity == 0 ? 4 : 2 * _capacity;
//        int* tmp = new int[newCapacity];
//        for(int i = 0; i < _size; ++i)
//        {
//            tmp[i] = _arr[i];
//        }
//        delete[] _arr;
//        _arr = tmp;
//        _capacity = newCapacity;
//        //std::cout << "扩容成功" << std::endl;
//    }
//    
//    int* _arr;
//    int _size;//保存的有效元素个数
//    int _capacity;//容量（能存放的元素个数）
//};
//void test12()
//{
//    SeqList s1;
//    s1.push_back(1);
//    s1.push_back(2);
//    s1.push_back(3);
//    s1.push_back(4);
//    s1.push_back(5);
//    s1.push_back(6);
//    s1.push_back(7);
//    s1.push_back(8);
//    s1.push_back(9);
//    s1.push_back(10);
//    s1.push_front(11);
//    s1.push_front(12);
//    s1.push_front(13);
//    s1.pop_front();
//    s1.pop_back();
//    s1.Print();
//}
//
//void test11()
//{
//    SeqListStatic s1;
//    s1.push_back(1);
//    s1.push_back(2);
//    s1.push_back(3);
//    s1.push_back(4);
//    s1.push_back(5);
//    s1.push_front(10);
//    s1.pop_back();
//    s1.insert(1, 20);
//    s1.insert(4, 30);
//    s1.Print();
//    int pos = s1.find(4);
//    if(pos != -1) s1.erase(pos);
//    s1.Print();
//    pos = s1.find(30);
//    if(pos != -1) s1.erase(pos);
//    s1.Print();
//}


////类模版
//template<class T>
//class vector
//{
//    
//};
using namespace std;
void test13()
{
    vector<int> v1;
    vector<int> v2 {1,2,3,4,5};
    //遍历v2有几种方式？
    //1.
    for(int i = 0; i < v2.size(); ++i)
    {
        cout << v2[i] << " " << v2.at(i) << " ";
    }
    cout << endl;
    //2. 迭代器方式
    //           reserve
    v2.resize(10, 7);
    cout << v2.capacity() << endl;
    v2.reserve(5);
    cout << v2.capacity() << endl;
    vector<int>::const_iterator it = v2.cbegin();
    while(it != v2.cend())
    {
        //*it *= 10;
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    //3. auto+范围for循环(C++11)
    //int a[5] = {5,4,3,2,1};
    for(auto& e : v2)
    {
        cout << e << " ";
    }
    cout << endl;
}
int main_1();
int main_2();
int main()
{
    main_2();
    return 0;
}

//string  vector
