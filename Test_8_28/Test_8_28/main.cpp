//
//  main.cpp
//  Test_8_28
//
//  Created by zht on 2023/8/28.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//void bfs(vector<vector<int>>& board)
//{
//
//}
//int main()
//{
//    int row,col,x,y;
//    cin >> row >> col >> x >> y;
//    vector<vector<int>> board(row);
//    for(auto& v : board)
//    {
//        v.resize(col, -1);
//    }
//
//    bfs(board);
//
//    for(auto& v : board)
//    {
//        for(auto& e : v)
//        {
//            cout << e << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    return 0;
//}


#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;
int main()
{
    int row, col, x, y;
    cin >> row >> col >> x >> y;
    int board[401][401];
    memset(board, -1, sizeof(board));
    board[x][y] = 0;
    int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
    int dy[8] = { -1,1,-2,2,2,-2,1,-1 };
    int temp = 1;
    int step = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        step++;
        while (temp--)
        {
            pair<int, int> pos = q.front();
            q.pop();
            for (int i = 0; i < 8; ++i)
            {
                int tmpx = pos.first + dx[i];
                int tmpy = pos.second + dy[i];
                if (tmpx >= 1 && tmpx <= row && tmpy >= 1 && tmpy <= col && board[tmpx][tmpy] == -1)
                {
                    board[tmpx][tmpy] = step;
                    q.push(make_pair(tmpx, tmpy));
                }
            }
        }
        temp = q.size();
    }

    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
