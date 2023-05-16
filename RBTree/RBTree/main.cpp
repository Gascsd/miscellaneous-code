//
//  main.cpp
//  RBTree
//
//  Created by zht on 2023/5/14.
//

#include <iostream>
#include <time.h>
#include <vector>
#include "RBTree.hpp"
using namespace std;

void TestRBTree1()
{
//    int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//    int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
    int a[] = { 57, 31, 71};
    RBTree<int, int> t;
    for (auto e : a)
    {
        t.Insert(make_pair(e, e));
    }
    cout << t.isRBTree() << endl;
}
void TestRBTree2()
{
    srand(time(0));
    const size_t N = 10;
    RBTree<int, int> t;
    for (size_t i = 0; i < N; ++i)
    {
        size_t x = rand() % 100;
        //cout << x << ":";
        t.Insert(make_pair(x, x));
        //cout << t.isRBTree() << endl;
    }
    cout << t.isRBTree() << endl;
}


int main()
{
    TestRBTree1();
    TestRBTree2();
    return 0;
}
