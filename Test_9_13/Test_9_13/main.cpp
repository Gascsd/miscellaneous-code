//
//  main.cpp
//  Test_9_13
//
//  Created by zht on 2023/9/13.
//

#include <iostream>
#include <queue>
using namespace std;

//int main()
//{
//    int a, b;
//    for(a = 1, b = 1; a <= 100; a++)
//    {
//        if(b >= 20) break;
//        if(b % 3 == 1)
//        {
//            b += 3;
//            continue;
//        }
//        b -= 5;
//    }
//    printf("%d\n", a);
//    return 0;
//}

struct node
{
    int val;
    node* next;
};

#define WHITE 1

enum color
{
    RED = 5,
    BLUE = 5,
    BLACK,//2
    YELLOW
};

int main()
{
    //int arr[5] = { 0 };
    //cout << typeid(arr).name() << endl;
//    color c = BLUE;
//    cout << c << endl;
//    queue<int> queue;
//    queue.push(1);
    
    char ch = 'a';
    char* pch = &ch;
    char* arr[5] = {pch};
    auto p =  &arr;
    cout << typeid(p).name() << endl;
    return 0;
}

