//
//  main.cpp
//  SmartPointer
//
//  Created by zht on 2023/8/12.
//

#include <iostream>
#include <memory>
#include <exception>
#include <thread>
#include "SmartPtr.h"
using namespace std;

double div()
{
    int a;
    int b;
    cin >> a >> b;
    if(b == 0)
    {
        throw invalid_argument(string("除0错误"));
    }
    return (double)a / (double)b;
}

void Func()
{
    int* p1 = new int;
    zht::auto_ptr<int> ap1(p1);
    int* p2 = new int;
    zht::auto_ptr<int> ap2(p2);
    cout << div() << endl;
}

void Test1()
{
    try{
        Func();
    }
    catch(exception& e)
    {
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "unknow Exception" << endl;
    }
}

void Test2()
{
    zht::auto_ptr<int> ap1(new int(10));
    ++*ap1;
    cout << *ap1 << endl;
    zht::auto_ptr<int> ap2(ap1);
    ++*ap2;
    cout << *ap2 << endl;
    //++*ap1;
}

//void Test3()
//{
//    unique_ptr<int> up1(new int(10));
//    unique_ptr<int> up2(up1);
//    unique_ptr<int> up3;
//    up3 = up1;
//}



void Test4()
{
    shared_ptr<int> sp1(new int(10));
    shared_ptr<int> sp2(sp1);
    
}

void Test5()
{
    int n = 100000;
    zht::shared_ptr<int> sp(new int(10));
    
    thread t1([&](){
        for(int i = 0; i < n; ++i)
        {
            zht::shared_ptr<int> sp2(sp);
        }
    });
    
    thread t2([&](){
        for(int i = 0; i < n; ++i)
        {
            zht::shared_ptr<int> sp3(sp);
        }
    });
    
    t1.join();
    t2.join();
    cout << sp.use_count() << endl;
}

struct ListNode
{
    int _val;
    zht::weak_ptr<ListNode> _prev;
    zht::weak_ptr<ListNode> _next;
    ListNode(int val = 0)
        :_val(val)
    {}
    ~ListNode()
    {
        cout << "ListNode" << endl;
    }
};

void  Test6()
{
    zht::shared_ptr<ListNode> n1(new ListNode);
    zht::shared_ptr<ListNode> n2(new ListNode);
    //链接两个节点
    n1->_next = n2;
    n2->_prev = n1;
}

int main()
{
    Test6();
    return 0;
}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int tree[500010],ranks[500010],n;
//long long ans;
//struct point
//{
//    int num,val;
//}a[500010];
//inline bool cmp(point q,point w)
//{
//    if(q.val==w.val)
//        return q.num<w.num;
//    return q.val<w.val;
//}
//inline void insert(int p,int d)
//{
//    for(;p<=n;p+=p&-p)
//        tree[p]+=d;
//}
//inline int query(int p)
//{
//    int sum=0;
//    for(;p;p-=p&-p)
//        sum+=tree[p];
//    return sum;
//}
//int main()
//{
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++)
//    {
//        scanf("%d",&a[i].val);
//        a[i].num=i;
//    }
//    sort(a+1,a+1+n,cmp);
//    for(int i=1;i<=n;i++)
//        ranks[a[i].num]=i;
//    for(int i=1;i<=n;i++)
//    {
//        insert(ranks[i],1);
//        ans+=i-query(ranks[i]);
//    }
//    printf("%lld",ans);
//    return 0;
//}
