//
//  main.cpp
//  Test_8_11
//
//  Created by zht on 2023/8/11.
//

#include <iostream>
#include <algorithm>
#include <thread>
using namespace std;

//int n;
//struct student
//{
//    char s1[20], s2[20];
//    int y, m;
//}a[50];
//bool Compare (const student& p1, const student& p2)
////这里运算符重载改成Compare，因为给sort用不能使用运算符重载（除非在类里面写）
//{
//    if(p1.y != p2.y)
//        return p1.y > p2.y;
//    return p1.m > p2.m;
//}
//int main()
//{
//    scanf("%d", &n);//这里你写的是n，需要加上&符号
//    for(int i = 1; i <= n; ++i)
//    {
//        scanf("%s %s %d %d", a[i].s1, a[i].s2, &a[i].y, &a[i].m);//这里对于%d输入的变量，需要加上取地址
//    }
//    sort(a+1, a+n+1, Compare);//这里排序需要传排序依据
//    for(int i = 1; i <= n; ++i)
//    {
//        printf("%s %s %d %d\n", a[i].s1, a[i].s2, a[i].y, a[i].m);
//        //这里输出的时候需要加上\n表示换行
//    }
//    return 0;
//}

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1)
            return true;
        if(n % 3 == 0)
            return isPowerOfThree(n/3);
        else
            return false;
    }
};

int at(vector<int>& v, size_t pos) //noexcept
{
    if (pos >= v.size())
        throw out_of_range("数组越界");
    else
        return v[pos];
}

void Test1()
{
    vector<int> v = {1, 2, 3, 4, 5};
    try {
        at(v, 5);
    }
    catch (out_of_range& errmsg)
    {
        cout << errmsg.what() << endl;
    }
    catch (...) {
        cout << "未知异常" << endl;
    }
}



class Exception//这里定义了一个异常的基类，后面对于不同类型的异常，将进行不同的继承
{
public:
    Exception(const string& errmsg, int id)
        :_errmsg(errmsg)
        ,_id(id)
    {}
    virtual string what() const//这里的what使用virtual修饰，以达到多态使用，返回不同的错误信息
    {
        return _errmsg;
    }
protected:
    string _errmsg;
    int _id;
};
class SqlException : public Exception//sql类型的异常
{
public:
    SqlException(const string& errmsg, int id, const string& sql)
        :Exception(errmsg, id)
        , _sql(sql)
    {}
    virtual string what() const//对虚函数进行重写，实现多态
    {
        //修改异常信息并返回
        string str = "SqlException:";
        str += _errmsg;
        str += "->";
        str += _sql;
        return str;
    }
private:
    const string _sql;//保存出现错误的sql语句
};
class CacheException : public Exception//Cache类型异常
{
public:
    CacheException(const string& errmsg, int id)
        :Exception(errmsg, id)
    {}
    virtual string what() const//虚函数重写
    {
        string str = "CacheException:";
        str += _errmsg;
        return str;
    }
};
class HttpServerException : public Exception//网络类型异常
{
public:
    HttpServerException(const string& errmsg, int id, const string& type)
        :Exception(errmsg, id)
        , _type(type)
    {}
    virtual string what() const
    {
        string str = "HttpServerException:";
        str += _type;
        str += ":";
        str += _errmsg;
        return str;
    }
private:
    const string _type;
};
void SQLMgr()
{
    srand(time(nullptr));
    if (rand() % 4 == 0)
    {
        throw SqlException("权限不足", 100, "select * from name = '张三'");
    }
    //throw "xxxxxx";
}
void CacheMgr()
{
    srand(time(0));
    if (rand() % 5 == 0)
    {
        throw CacheException("权限不足", 100);
    }
    else if (rand() % 6 == 0)
    {
        throw CacheException("数据不存在", 101);
    }
    SQLMgr();//如果没有抛出异常就调用SQL层操作
}
void HttpServer()
{
    // ...
    srand(time(0));
    if (rand() % 3 == 0)
    {
        throw HttpServerException("请求资源不存在", 100, "get");
    }
    else if (rand() % 4 == 0)
    {
        throw HttpServerException("权限不足", 101, "post");
    }
    CacheMgr();//如果网络服务没有问题，在这里调用内存操作
}
void Test3()
{
    while(1)
    {
        this_thread::sleep_for(chrono::seconds(1));
        try{
            HttpServer();//这里调用网络服务
        }
        catch (const Exception& e) // 这里捕获父类对象就可以
        {
            // 多态
            cout << e.what() << endl;
        }
        catch (...)
        {
            cout << "Unkown Exception" << endl;
        }
    }
}

int main()
{
//    int n = 9;
//    bool ret = Solution( ).isPowerOfThree(n);
//    if(ret)
//        cout << "true" << endl;
//    else
//        cout << "false" << endl;
    Test3();
    return 0;
}
