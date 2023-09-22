//
//  main.cpp
//  Test_9_20
//
//  Created by zht on 2023/9/20.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
//单例模式
//懒汉模式
class Singleton
{
public:
    static Singleton& GetInstance()
    {
        return _ins;
    }
    void Insert(pair<string, int> val)
    {
        _mp.insert(val);
    }
    void Print()
    {
        for(auto& kv : _mp)
        {
            cout << kv.first << ":" << kv.second << endl;
        }
    }
private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton operator=(const Singleton&) = delete;
private:
    static Singleton _ins;
    map<string,int> _mp;
};

Singleton Singleton::_ins;//在程序开始执行main函数之前就已经构造对象

template<class Mutex>
class LockGuard
{
public:
    LockGuard(Mutex& mtx)
    :_mtx(mtx)
    {
        _mtx.lock();
    }
    ~LockGuard()
    {
        _mtx.unlock();
    }
private:
    Mutex& _mtx;//这里需要将锁设为引用的，因为锁不允许拷贝
};

class SlackerInstance
{
public:
    
    static SlackerInstance* GetInstance()
    {
        if(_pins == nullptr)//双检查，避免无意义的加锁解锁
        {
            //_mtx.lock();//加锁
            LockGuard<std::mutex> lg(_mtx);
            if(_pins == nullptr)//第一次获取单例对象的时候创建对象
            {
                _pins = new SlackerInstance;
            }
            //_mtx.unlock();//完成new操作之后解锁
        }
        return _pins;
    }
    static void DelInstance()
    {
        //保存数据文件
        //TODO
        
        //回收单例对象资源
        std::lock_guard<std::mutex> lg(_mtx);
        if(_pins != nullptr)
        {
            delete _pins;
            _pins = nullptr;
        }
    }
    void Insert(pair<string, int> val)
    {
        _mp.insert(val);
    }
    void Print()
    {
        for(auto& kv : _mp)
        {
            cout << kv.first << ":" << kv.second << endl;
        }
    }
    class GC
    {
    public:
        ~GC()
        {
            if(_pins)
            {
                cout << "~GC()" << endl;
                DelInstance();
            }
        }
    };
private:
    SlackerInstance() {}//构造函数私有化
    SlackerInstance(const SlackerInstance&) = delete;//删除拷贝构造和赋值重载
    SlackerInstance operator=(const SlackerInstance&) = delete;
private:
    static SlackerInstance* _pins;//静态的单例对象指针
    static mutex _mtx;//互斥锁
    static GC _gc;//自动回收
    map<string, int> _mp;
};

SlackerInstance* SlackerInstance::_pins = nullptr;//初始化为空指针
mutex SlackerInstance::_mtx;
SlackerInstance::GC SlackerInstance::_gc;

class SlackerInstance2
{
public:
    static SlackerInstance2& GetInstance()
    {
        static SlackerInstance2 ins;//使用static修饰吗，第一次调用的时候构建对象，再次调用就直接使用
        return ins;
    }
    void Insert(pair<string, int> val)
    {
        _mp.insert(val);
    }
    void Print()
    {
        for(auto& kv : _mp)
        {
            cout << kv.first << ":" << kv.second << endl;
        }
    }
private:
    SlackerInstance2(){}
    SlackerInstance2(const SlackerInstance2&) = delete;
    SlackerInstance2 operator=(const SlackerInstance2&) = delete;
private:
    map<string, int> _mp;
};

void test1()
{
    auto& ins1 = Singleton::GetInstance();
    ins1.Insert({"sort", 1});
    
    auto& ins2 = Singleton::GetInstance();
    ins2.Insert({"string", 3});
    
    auto& ins3 = Singleton::GetInstance();
    ins3.Print();
}

void test2()
{
    SlackerInstance* pins1 = SlackerInstance::GetInstance();
    pins1->Insert({"sort", 1});
    
    SlackerInstance* pins2 = SlackerInstance::GetInstance();
    pins1->Insert({"string", 2});
    
    SlackerInstance* pins3 = SlackerInstance::GetInstance();
    pins3->Print();
}
void test3()
{
    SlackerInstance2& ins1 = SlackerInstance2::GetInstance();
    ins1.Insert({"sort", 1});
    
    SlackerInstance2& ins2 = SlackerInstance2::GetInstance();
    ins1.Insert({"string", 2});
    
    SlackerInstance2& ins3 = SlackerInstance2::GetInstance();
    ins3.Print();
}
int main()
{
    test3();
    return 0;
}
