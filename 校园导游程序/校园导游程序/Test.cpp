#define _CRT_SECURE_NO_WARNINGS 1
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string>
#include <stack>
#include <deque>
using namespace std;
#define MAX 0x3f3f3f
stack<int> S;
deque <int> dq;
deque <deque<int> > dd;
int mapp[16][16];//步行
int mapp1[16][16];//驾车
int dis[16], vis[16];
int path[20];
int flag[200] = { 0 };
int e = 0;
int aa[20] = { 0 };
void init();//最初将长度存好
void Query();//查询景点编号，信息，简介
void Query1();//查询两点任意最短路径及长度;
void DIS(int a, int b, int c);//计算dis数组
void dijstra(int b, int a, int c);//回溯求最短路径
void Query2();//查询两点所有路径
void QQ(int a);//最佳路径
void Query3();//查询途经多点的最短路径
void menu();//实现菜单功能
void init()
{
    memset(mapp, MAX, sizeof(mapp));
    memset(mapp1, MAX, sizeof(mapp));
    memset(dis, MAX, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    mapp[1][2] = mapp[2][1] = 80;
    mapp[1][3] = mapp[3][1] = 100;
    mapp[1][12] = mapp[12][1] = 80;
    mapp[1][15] = mapp[15][1] = 30;
    mapp[2][3] = mapp[3][2] = 100;
    mapp[3][4] = mapp[4][3] = 70;
    mapp[3][12] = mapp[12][3] = 100;
    mapp[4][5] = mapp[5][4] = 40;
    mapp[4][7] = mapp[7][4] = 100;
    mapp[5][6] = mapp[6][5] = 150;
    mapp[6][8] = mapp[8][6] = 200;
    mapp[7][8] = mapp[8][7] = 50;
    mapp[7][10] = mapp[10][7] = 50;
    mapp[7][11] = mapp[11][7] = 20;
    mapp[8][9] = mapp[9][8] = 20;
    mapp[8][10] = mapp[10][8] = 30;
    mapp[9][10] = mapp[10][9] = 40;
    mapp[9][14] = mapp[14][9] = 40;
    mapp[10][11] = mapp[11][10] = 20;
    mapp[10][14] = mapp[14][10] = 30;
    mapp[11][12] = mapp[12][11] = 70;
    mapp[12][13] = mapp[13][12] = 20;
    mapp[12][15] = mapp[15][12] = 50;
    mapp[13][14] = mapp[14][13] = 20;
    mapp1[1][3] = mapp1[3][1] = 120;
    mapp1[1][12] = mapp1[12][1] = 80;
    mapp1[12][11] = mapp1[11][12] = 70;
    mapp1[1][13] = mapp1[13][1] = 100;
    mapp1[1][15] = mapp1[15][1] = 30;
    mapp1[3][4] = mapp1[4][3] = 70;
    mapp1[4][5] = mapp1[5][4] = 40;
    mapp1[5][6] = mapp1[6][5] = 150;
    mapp1[6][8] = mapp1[8][6] = 200;
    mapp1[6][9] = mapp1[9][6] = 300;
    mapp1[9][14] = mapp1[14][9] = 40;
    mapp1[13][14] = mapp1[14][13] = 20;
}
void Query()
{
    int a;
    cout << "=========景点编号=========" << endl;
    cout << "= 1. 南门       2. 操场    =" << endl;
    cout << "= 3. 图书馆     4. 四教    =" << endl;
    cout << "= 5. A座        6. B座     =" << endl;
    cout << "= 7. 二教       8. 一教    =" << endl;
    cout << "= 9. 三教       10. 五教   =" << endl;
    cout << "= 11. 体育馆    12. 六教   =" << endl;
    cout << "= 13. C座       14. D座    =" << endl;
    cout << "= 15. 雕塑源泉  16. 小北门 =" << endl;
    cout << "==========================" << endl;
    cout << "输入你想查询景点信息的编号(1 ~ 15)：";
    cin >> a;
    if (a == 1)
        cout << "* 安徽工程大学大门，因面朝南面被称为南门!" << endl;
    if (a == 2)
        cout << "* 操场有400米跑道，足球场，可以进行户外活动！" << endl;
    if (a == 3)
        cout << "* 图书馆可以借书，上自习，进入需刷校园卡进入！" << endl;
    if (a == 4)
        cout << "* 这里是4j，可以用于自习，日常上课的地方！！" << endl;
    if (a == 5)
        cout << "* 这里是A座，政务中心，学校领导办公的地方！" << endl;
    if (a == 6)
        cout << "* 材料科学与工程学院！" << endl;
    if (a == 7)
        cout << "* 这里是2j，可以用于自习，日常上课的地方！" << endl;
    if (a == 8)
        cout << "* 这里是1j，可以用于自习，日常上课的地方！" << endl;
    if (a == 9)
        cout << "* 这里是3j，可以用于自习，日常上课的地方！" << endl;
    if (a == 10)
        cout << "* 这里是4j，可以用于自习，日常上课的地方！" << endl;
    if (a == 11)
        cout << "* 这里是学校体育馆，有室内的篮球场和羽毛球场！" << endl;
    if (a == 12)
        cout << "* 这里是6j，可以用于自习，日常上课的地方！" << endl; 
    if (a == 13)
        cout << "* 计算机与信息学院！" << endl; 
    if (a == 14)
        cout << "* 纺织与服装学院！" << endl;
    if (a == 15)
        cout << "* 雕塑源泉，这里是学校的地标！" << endl;
    if (a == 16)
        cout << "* 小北门，距离学生宿舍很近，所以很多学生倾向于选择走这个门！" << endl;
}
void Query1()
{
    int a, b, c;
    cout << "======出行方式=====" << endl;
    cout << "1.步行." << endl;
    cout << "2.驾车." << endl;
    cout << "=================" << endl;
    cout << "输入你的选择(1 or 2)：";
    cin >> a;
    cout << "输入起点编号：";
    cin >> b;
    cout << "输入终点编号：";
    cin >> c;
    if (b <= 0 && b > 20 || c <= 0 && c > 20)
        cout << "输入错误，景点不存在。" << endl;
    else
        dijstra(b, a, c);
}
void DIS(int a, int b, int c)//计算dis数组
{
    memset(path, 0, sizeof(path));
    int i, j, pos = 1, minn, sum = 0;
    memset(vis, 0, sizeof(vis));
    for (i = 1; i <= 15; i++)
    {
        if (a == 1)
            dis[i] = mapp[b][i];
        if (a == 2)
            dis[i] = mapp1[b][i];
    }
    vis[b] = 1;
    dis[b] = 0;
    for (i = 1; i <= 15; i++)
    {
        minn = MAX;
        for (j = 1; j <= 15; j++)
        {
            if (vis[j] == 0 && minn > dis[j])
            {
                minn = dis[j];
                pos = j;
            }
        }
        vis[pos] = 1;
        for (j = 1; j <= 15; j++)
        {
            if (a == 1)
            {
                if (vis[j] == 0 && dis[j] > dis[pos] + mapp[pos][j])
                {
                    dis[j] = dis[pos] + mapp[pos][j];
                    path[j] = pos;
                }
            }
            if (a == 2)
            {
                if (vis[j] == 0 && dis[j] > dis[pos] + mapp1[pos][j])
                {
                    dis[j] = dis[pos] + mapp1[pos][j];
                    path[j] = pos;
                }
            }
        }
    }
}
void dijstra(int b, int a, int c)
{
    DIS(a, b, c);
    int x = c;
    while (!S.empty())
        S.pop();
    //    for(i=1;i<=15;i++)
    //        cout<<i<<" "<<path[i]<<endl;
    //    cout<<endl;
    while (1)
    {
        if (x == 0)
            break;
        S.push(x);
        x = path[x];
    }
    S.push(b);
    if (dis[c] >= 100000)
        cout << "没有直达的路，请选择步行。" << endl;
    else
    {
        cout << "从" << b << "到" << c << "的最短路径为：";
        while (!S.empty())
        {
            if (S.size() > 1)
                cout << S.top() << "->";
            else
                cout << S.top();
            S.pop();
        }
        cout << endl << "其最短距离为：" << dis[c] << endl;
    }

}
void DFS1(int b, int c)
{
    int i, j;
    vis[b] = 1;
    dq.push_back(b);
    for (j = 1; j <= 15; j++)
    {
        if (j == c && mapp[j][b] <= 2000)
        {
            dd.push_back(dq);
            //return ;
        }
        if (vis[j] == 0 && mapp[b][j] <= 2000)
            DFS1(j, c);
    }
    vis[dq.back()] = 0;
    dq.pop_back();
}
void DFS2(int b, int c)
{
    int i, j;
    vis[b] = 1;
    dq.push_back(b);
    for (j = 1; j <= 15; j++)
    {
        if (j == c && mapp1[j][b] <= 2000)
        {
            dd.push_back(dq);
            //            return;
        }
        if (vis[j] == 0 && mapp1[b][j] <= 2000)
            DFS2(j, c);
    }
    vis[dq.back()] = 0;
    dq.pop_back();
}
void Query2()
{
    init();
    int a, b, c, i, j;
    cout << "======出行方式=====" << endl;
    cout << "    1.步行." << endl;
    cout << "    2.驾车." << endl;
    cout << "===================" << endl;
    cout << "输入你的选择(1 or 2)：";
    cin >> a;
    cout << "输入起点编号：";
    cin >> b;
    cout << "输入终点编号：";
    cin >> c;
    // 队列 数组清零
    while (!dq.empty())
        dq.pop_front();
    while (!dd.empty())
        dd.pop_front();
    memset(vis, 0, sizeof(vis));
    if (a == 1)
        DFS1(b, c);
    else
        DFS2(b, c);
    if (dd.size() >= 3)
    {
        cout << "有三条以上（含3条），只输出前三条较短的路径:" << endl;
        int p = 0;
        for (i = 1;; i++)
        {
            int g = dd.size();
            for (j = 0; j < g; j++)
            {
                if (dd.front().size() == i)
                {
                    while (!dd.front().empty())
                    {
                        cout << dd.front().front() << " ";
                        dd.front().pop_front();
                    }
                    cout << c << endl;
                    p++;
                    if (p == 3)
                        return;
                    dd.pop_front();
                    continue;
                }
                dd.push_back(dd.front());
                dd.pop_front();
            }
        }
    }
    else if (dd.size() != 0)
    {

        while (!dd.empty())
        {
            while (!dd.front().empty())
            {
                cout << dd.front().front() << " ";
                dd.front().pop_front();
            }
            cout << c << endl;
            dd.pop_front();
        }
    }
    else
        cout << "没有直接相连的路径!!!" << endl;

}

void QQ(int a)
{
    int i, j, k, flag1 = 0;
    // 队列 数组清零
    while (!dq.empty())
        dq.pop_front();
    while (!dd.empty())
        dd.pop_front();
    memset(vis, 0, sizeof(vis));
    //cout<<aa[e-1]<<"**"<<endl;
    if (a == 1)
        DFS1(aa[0], aa[e - 1]);
    else
        DFS2(aa[0], aa[e - 1]);
    int n = dd.size();
    int yang = 0;
    //DIS(a,aa[0],aa[e-1]);
    //cout<<" *****"<<n<<endl;
    for (k = 1; k <= 20; k++)
    {
        for (i = 0; i < n; i++)
        {
            int m = dd.front().size();
            int sum = 0;
            //cout<<"******"<<m<<endl;
            for (j = 0; j < m; j++)
            {
                int hh = dd.front().front();
                if (flag[hh] == 1)
                    sum++;
                dd.front().pop_front();
                dd.front().push_back(hh);
            }
            //cout<<"++++++"<<e-1<<endl;
            //cout<<"******"<<sum<<endl;
            if (sum >= e - 1 && m == k)
            {
                flag1 = 1;
                yang++;
                if (yang == 2)
                    return;
                cout << "路径为：";
                for (j = 0; j < m; j++)
                    // while(!dd.front().empty())
                {
                    cout << dd.front().front() << " ";
                    dd.front().push_back(dd.front().front());
                    dd.front().pop_front();
                }
                cout << aa[e - 1] << " ";
                cout << endl;
                //cout<<"其路径长度为："<<dis[aa[e-1]]<<endl;
            }
            dd.push_back(dd.front());
            dd.pop_front();
        }

    }if (flag1 == 0)
        cout << "**不存在这样的路径" << endl;
}
void Query3()
{
    init();
    int a;
    memset(aa, 0, sizeof(aa));
    memset(flag, 0, sizeof(flag));
    cout << "======出行方式=====" << endl;
    cout << "    1.步行." << endl;
    cout << "    2.驾车." << endl;
    cout << "===================" << endl;
    cout << "输入你的选择(1 or 2)：";
    cin >> a;
    cout << "输入经过的点（以0结束,默认开始为起始点）：";
    int b;
    while (1)
    {
        cin >> b;
        if (b == 0)
            break;
        else
        {
            aa[e++] = b;
            flag[b] = 1;
        }
    }
    aa[e] = 0;
    // Prim(a,aa[0]);
    QQ(a);
}
void PP()
{
    cout << "======================================安工程平面图==================================" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "|                                               | 1.南门 |--------------------------|" << endl;
    cout << "|                          ----------            |      |                           |" << endl;
    cout << "|                          | 4.四教 |-------------      ----------------------------|" << endl;
    cout << "|              --------    ----------   |                                   |       |" << endl;
    cout << "|              | 5.A座|       ----------   |                                |  3    |" << endl;
    cout << "|              --------       | 7.二教 |---                                 | 图书馆|" << endl;
    cout << "|              | 6.B座|       ----------   |           -----------          |       |" << endl;
    cout << "|  --------    --------       ----------   |           |   15    |          --------|" << endl;
    cout << "|  |10.五教|   |13.C座|       | 9.三教 |---|-----------| 源泉雕塑|------------------|" << endl;
    cout << "|  --------    --------       ----------   |           |         |        | 8.一教 ||" << endl;
    cout << "|  |12.六教|   |14.D座|                                 -----------       --------- |" << endl;
    cout << "|  --------    --------                                                             |" << endl;
    cout << "|                        -----------           ---------------                      |" << endl;
    cout << "|                        |11.体育馆 |         |               |                     |" << endl;
    cout << "|                        |          |         |   2.操场      |                     |"<< endl;
    cout << "|                        -----------          |               |                     |" << endl;
    cout << "|                                             |               |                     |" << endl;
    cout << "|                                              ---------------                      |" << endl;
    cout << "|                                                                |16.小北门|        |" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

}
void menu()
{
    int a;
    init();
    while (1)
    {
        cout << "============菜单============" << endl;
        cout << "0.退出." << endl;
        cout << "1.查询所有景点信息." << endl;
        cout << "2.查询两景点的最短路径." << endl;
        cout << "3.查询两景点的所有路径." << endl;
        cout << "4.查询多景点的最佳路径." << endl;
        cout << "5.安徽工程大学平面图." << endl;
        cout << "===========================" << endl;
        cout << "输入你的选择(0 ~ 5)：";
        cin >> a;
        if (a == 0)
            break;
        if (a == 1)
            Query();
        if (a == 2)
            Query1();
        if (a == 3)
            Query2();
        if (a == 4)
            Query3();
        if (a == 5)
            PP();
        system("pause");
        system("cls");
    }
}
int main()
{
    menu();
    //PP();
    return 0;
}