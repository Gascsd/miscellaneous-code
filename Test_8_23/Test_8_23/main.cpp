//
//  main.cpp
//  Test_8_23
//
//  Created by zht on 2023/8/23.
//

#include <iostream>
#include <queue>
#include "queue.h"
#include "list.h"
int main()
{
    my::queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);
    q1.push(7);
    std::cout << "size:" << q1.size() << std::endl;
    while (!q1.empty())
    {
        std::cout << q1.front() << " ";
        q1.pop();
    }
    std::cout << std::endl;
    std::cout << q1.front() << std::endl;
    return 0;
}
