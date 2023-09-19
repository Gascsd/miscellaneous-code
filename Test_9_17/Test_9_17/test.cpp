//
//  test.cpp
//  Test_9_17
//
//  Created by zht on 2023/9/17.
//

#include "test.hpp"

//#define RED 0
//#define BLUE 1
//#define BLACK 2
//#define GREEN 3
//#define YELLOW 4

#define PICK 4

enum Color
{
    RED,
    BLUE,
    BLACK,
    GREEN,
    YELLOW
};

//void test1()
//{
//    Color n = PICK;
//    //...
//
//    switch (n) {
//        case RED:
//            cout << n << endl;
//            break;
//        case BLUE:
//            cout << n << endl;
//            break;
//        case BLACK:
//            cout << n << endl;
//            break;
//        case GREEN:
//            cout << n << endl;
//            break;
//        case YELLOW:
//            cout << n << endl;
//            break;
//
//    }
//}

void menu()
{
    cout << "*************猜数字游戏***********" << endl;
    cout << "*************1.进入游戏***********" << endl;
    cout << "*************0.退出游戏***********" << endl;
    cout << "请输入：";
}
enum Status
{
    EXIT = 0,
    START = 1
};
void Game()
{
    //cout << "游戏内容" << endl;
    int in = 0;
    int num = rand() % 100 + 1;
    while(1)
    {
        cout << "请输入你要猜的数：";
        cin >> in;
        if(in > num)
        {
            cout << "猜大了，请重新猜" << endl;
        }
        else if (in < num)
        {
            cout << "猜小了，请重新猜" << endl;
        }
        else
        {
            cout << "恭喜你，猜对啦，游戏结束！！" << endl;
            break;
        }
    }
}
void game()
{
    srand(time(0));
    int input = 0;
    do
    {
        menu();
        cin >> input;
        switch (input) {
            case EXIT:
                cout << "exit" << endl;
                return;
                break;
            case 1:
                cout << "游戏开始" << endl;
                Game();
                break;
            default:
                cout << "输入错误，请重新输入" << endl;
                break;
        }
    }while(true);
}
int main_1()
{
    game();
    return 0;
}


