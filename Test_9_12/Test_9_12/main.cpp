//
//  main.cpp
//  Test_9_12
//
//  Created by zht on 2023/9/12.
//

#include <iostream>
#include <queue>
using namespace std;

const int ROWS = 8;
const int COLS = 8;

struct Point
{
    int r, c;
    Point(int r, int c) : r(r), c(c) {}
};

bool is_valid(char image[ROWS][COLS], Point pt, int prev_color, int new_color)
{
    int r = pt.r;
    int c = pt.c;
    return (0 <= r && r < ROWS && 0 <= c && c < COLS && image[r][c] == prev_color && image[r][c] != new_color);// 1 合法情况就是当前点必须是prev_color颜色的
}

void flood_fill(char image[ROWS][COLS], Point cur, int new_color)
{
    queue<Point> queue;
    queue.push(cur);
    
    int prev_color = image[cur.r][cur.c];
    /*2*/
    image[cur.r][cur.c] = new_color;//把cur的颜色更新
    
    while (!queue.empty())
    {
        Point pt = queue.front();
        queue.pop();
        
        Point points[4] = { Point(pt.r + 1, pt.c), Point(pt.r - 1, pt.c), Point(pt.r, pt.c + 1), Point(pt.r, pt.c - 1)};/*3,*/
        for(auto p : points)
        {
            if(is_valid(image, p, prev_color, new_color))
            {
                //4
                image[p.r][p.c] = new_color;
                //5
                queue.push(p);
            }
        }
    }
}

pair<int, int> arr[4] = {{0,1}, {0,-1}, {1,0}, {-1, 0}};


int main()
{
    char image[ROWS][COLS] =
    {
        {'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
        {'g', 'g', 'g', 'g', 'g', 'g', 'r', 'r'},
        {'g', 'r', 'r', 'g', 'g', 'r', 'g', 'g'},
        {'g', 'b', 'b', 'b', 'b', 'r', 'g', 'r'},
        {'g', 'g', 'g', 'b', 'b', 'r', 'g', 'r'},
        {'g', 'g', 'g', 'b', 'b', 'b', 'b', 'r'},
        {'g', 'g', 'g', 'g', 'g', 'b', 'g', 'g'},
        {'g', 'g', 'g', 'g', 'g', 'b', 'b', 'g'}
    };
    Point cur(4,4);
    char new_color = 'y';
    
    flood_fill(image, cur, new_color);
    
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            cout << image[r][c] << " ";
        }
        cout << endl;
    }
    return 0;
//    g g g g g g g g
//    g g g g g g r r
//    g r r g g r g g
//    g b b b b r g r
//    g g g b b r g r
//    g g g b b b b r
//    g g g g g b g g
//    g g g g g b b g
}
