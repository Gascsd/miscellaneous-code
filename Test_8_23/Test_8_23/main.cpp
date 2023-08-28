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
void Test1()
{
    std::cout << "--------Test My Queue--------" << std::endl;
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
    
    std::cout << "--------Test My Stack--------" << std::endl;
    my::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    st.push(11);
    st.push(12);
    std::cout << "size:" << st.size() << std::endl;
    while(!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
    std::cout << st.top() << std::endl;
}

void Test_list()
{
    my::test_list_pop_back();
}
int main()
{
    //Test_list();
    Test1();
    return 0;
}
