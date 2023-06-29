//
//  main.cpp
//  Test_6_24
//
//  Created by zht on 2023/6/24.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <time.h>
#include <assert.h>
#include <limits.h>
using namespace std;

#define Black 0 // 定义空以及黑白棋
#define White 1
#define Empty 2
#define W1 16 // 生成的着法集中第一步着法的个数
#define W2 16 // 生成的着法集中第二步着法的个数

int computerside; // 己方执棋颜色
// 表示点的坐标，其中有横纵坐标和一个value标志该点的权值
struct Point
{
    int _x;
    int _y;
    int _value;
    Point(int x = -1, int y = -1, int value = 0) : _x(x), _y(y), _value(value){};
};
struct Step
{
    pair<Point, Point> _point; // 两步着法
    int _value;                // 当前着法的权值
    Step(pair<Point, Point> point = make_pair(Point(), Point()), int value = 0)
        : _point(point), _value(value)
    {
    }
};

int Evaluate(Step step, vector<vector<int>> curBoard);
// 仿函数，用于比较走法的权值
struct Compare
{
    bool operator()(Point x, Point y)
    {
        return x._value < y._value;
    }
};
void test_alphabeta() {
    // Test case 1
    vector<vector<int>> board = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int player = 1;
    int depth = 2;
    int alpha = INT_MIN;
    int beta = INT_MAX;
    pair<int, int> expected_move = {1, 1};

    // Test case 2
    board = {
        {1, -1, -1},
        {0, 1, -1},
        {0, 0, 0}
    };
    player = -1;
    depth = 3;
    alpha = INT_MIN;
    beta = INT_MAX;
    expected_move = {2, 2};
}

void chessBoard_init(vector<vector<int>> &board); // 棋盘初始化函数
Step GetFirstStep();                              // 生成首步走法的函数
// 按权值排序的着发生成器
vector<Point> _GetStepSet(vector<vector<int>> curBoard);
queue<Step> GetStepSet(vector<vector<int>> curBoard);

bool IsGameOver(vector<vector<int>> curBoard);
// AlphaBeta剪枝算法
Step AlphaBeta(vector<vector<int>> curBoard, int alpha, int beta, int status, int depth = 5)
{
    // 如果达到了最大深度或者已经有一方胜利了，则返回当前局面的估值
    if (depth == 0)
    {
        Step step;
        step._value = Evaluate(step, curBoard);
        return step;
    }
    // 生成当前局面下所有可能的走法
    queue<Step> steps = GetStepSet(curBoard);
    // 如果当前是电脑走棋
    if (status == computerside)
    {
        Step bestStep;
        bestStep._value = -1000000;
        while (!steps.empty())
        {
            Step step = steps.front();
            steps.pop();
            vector<vector<int>> newBoard = curBoard;
            
            newBoard[step._point.first._x][step._point.first._y] = Empty;
            newBoard[step._point.second._x][step._point.second._y] = computerside;
            Step nextStep = AlphaBeta(newBoard, alpha, beta, 1 - status, depth - 1);
            if (nextStep._value > bestStep._value)
            {
                bestStep = step;
                bestStep._value = nextStep._value;
            }
            alpha = max(alpha, bestStep._value);
            if (beta <= alpha)
                break;
        }
        return bestStep;
    }
    // 如果当前是玩家走棋
    else
    {
        Step bestStep;
        bestStep._value = 1000000;
        while (!steps.empty())
        {
            Step step = steps.front();
            steps.pop();
            vector<vector<int>> newBoard = curBoard;
            newBoard[step._point.first._x][step._point.first._y] = Empty;
            newBoard[step._point.second._x][step._point.second._y] = computerside ^ 1;
            Step nextStep = AlphaBeta(newBoard, alpha, beta, 1 - status, depth - 1);
            if (nextStep._value < bestStep._value)
            {
                bestStep = step;
                bestStep._value = nextStep._value;
            }
            beta = min(beta, bestStep._value);
            if (beta <= alpha)
                break;
        }
        return bestStep;
    }
}

int main()
{
    srand(time(0));
    // cout << "test" << endl;
    test_alphabeta();
    return 0;
}
