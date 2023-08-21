//
//  SmartPtr.h
//  SmartPointer
//
//  Created by zht on 2023/8/12.
//

#ifndef SmartPtr_h
#define SmartPtr_h

namespace zht
{
template<class T>
class auto_ptr
{
public:
    auto_ptr(T* ptr = nullptr)
        :_ptr(ptr)
    {}
    auto_ptr(auto_ptr<T>& ap)
    {
        _ptr = ap._ptr;
        ap._ptr = nullptr;
    }
    auto_ptr<T>& operator=(auto_ptr<T>& ap)
    {
        _ptr = ap._ptr;
        ap._ptr = nullptr;
        return *this;
    }
    T& operator*()
    {
        return *_ptr;
    }
    T* operator->()
    {
        return _ptr;
    }
    ~auto_ptr()
    {
        if(_ptr != nullptr)
        {
            delete _ptr;
        }
    }
private:
    T* _ptr;
};

template<class T>
class unique_ptr
{
public:
    unique_ptr(T* ptr = nullptr)
        :_ptr(ptr)
    {}
    ~unique_ptr()
    {
        if(_ptr)
            delete _ptr;
    }
    unique_ptr(unique_ptr<T>& up) = delete;
    unique_ptr<T>& operator=(unique_ptr<T>& up) = delete;
    T& operator*()
    {
        return *_ptr;
    }
    T* operator->()
    {
        return _ptr;
    }
private:
    T* _ptr;
};

template<class T>
class shared_ptr
{
public:
    shared_ptr(T* ptr = nullptr)//默认构造
        :_ptr(ptr)
        ,_pcount(new int(1))
    {}
    ~shared_ptr()//析构
    {
        Release();
    }
    void Release()
    {
        if(--(*_pcount) == 0)
        {
            delete _ptr;
            delete _pcount;
        }
    }
    shared_ptr(const shared_ptr<T>& sp)//拷贝构造
        :_ptr(sp._ptr)
        ,_pcount(sp._pcount)
    {
        ++(*_pcount);
    }
    shared_ptr<T>& operator=(const shared_ptr<T>& sp)//赋值重载
    {
        if(sp._ptr != _ptr)//不是同一块内存地址
        {
            Release();
            _ptr = sp._ptr;
            _pcount = sp._pcount;
            ++*_pcount;
        }
        return *this;
    }
    T& operator*()
    {
        return *_ptr;
    }
    T* operator->()
    {
        return _ptr;
    }
    int use_count()//引用次数
    {
        return *_pcount; 
    }
    T* get()//拿到地址
    {
        return _ptr;
    }
private:
    T* _ptr;
    int* _pcount;
};
template<class T>
class weak_ptr
{
public:
    weak_ptr(T* ptr = nullptr)//空的默认构造函数
        :_ptr(ptr)
    {}
    weak_ptr(const shared_ptr<T>& sp)//使用shared_ptr对象构造weak_ptr对象
        :_ptr(sp.get())
    {}
    weak_ptr<T>& operator=(shared_ptr<T>& sp)//赋值重载
    {
        _ptr = sp.get();
        return *this;
    }
    T& operator*()
    {
        return *_ptr;
    }
    T* operator->()
    {
        return _ptr;
    }
private:
    T* _ptr;
};
}



#endif /* SmartPtr_h */
