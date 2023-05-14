//
//  main.cpp
//  AVLTree
//
//  Created by zht on 2023/5/14.
//

#include <iostream>
#include "AVLTree.hpp"
#include <time.h>

void TestAVLTree1()
{
    //int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
    //int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
    AVLTree<int, int> t;
    for (auto e : a)
    {
        t.Insert(make_pair(e, e));
    }

    cout << t.isBalance() << endl;
}
void TestAVLTree2()
{
    srand(time(0));
    const size_t N = 10000;
    AVLTree<int, int> t;
    for (size_t i = 0; i < N; ++i)
    {
        size_t x = rand();
        t.Insert(make_pair(x, x));
        //cout << t.IsBalance() << endl;
    }


    cout << t.isBalance() << endl;
}

int main()
{
    TestAVLTree1();
    TestAVLTree2();
    return 0;
}
