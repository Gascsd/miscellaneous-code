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
int mapp[16][16];//����
int mapp1[16][16];//�ݳ�
int dis[16], vis[16];
int path[20];
int flag[200] = { 0 };
int e = 0;
int aa[20] = { 0 };
void init();//��������ȴ��
void Query();//��ѯ�����ţ���Ϣ�����
void Query1();//��ѯ�����������·��������;
void DIS(int a, int b, int c);//����dis����
void dijstra(int b, int a, int c);//���������·��
void Query2();//��ѯ��������·��
void QQ(int a);//���·��
void Query3();//��ѯ;���������·��
void menu();//ʵ�ֲ˵�����
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
    cout << "=========������=========" << endl;
    cout << "= 1. ����       2. �ٳ�    =" << endl;
    cout << "= 3. ͼ���     4. �Ľ�    =" << endl;
    cout << "= 5. A��        6. B��     =" << endl;
    cout << "= 7. ����       8. һ��    =" << endl;
    cout << "= 9. ����       10. ���   =" << endl;
    cout << "= 11. ������    12. ����   =" << endl;
    cout << "= 13. C��       14. D��    =" << endl;
    cout << "= 15. ����ԴȪ  16. С���� =" << endl;
    cout << "==========================" << endl;
    cout << "���������ѯ������Ϣ�ı��(1 ~ 15)��";
    cin >> a;
    if (a == 1)
        cout << "* ���չ��̴�ѧ���ţ����泯���汻��Ϊ����!" << endl;
    if (a == 2)
        cout << "* �ٳ���400���ܵ������򳡣����Խ��л�����" << endl;
    if (a == 3)
        cout << "* ͼ��ݿ��Խ��飬����ϰ��������ˢУ԰�����룡" << endl;
    if (a == 4)
        cout << "* ������4j������������ϰ���ճ��Ͽεĵط�����" << endl;
    if (a == 5)
        cout << "* ������A�����������ģ�ѧУ�쵼�칫�ĵط���" << endl;
    if (a == 6)
        cout << "* ���Ͽ�ѧ�빤��ѧԺ��" << endl;
    if (a == 7)
        cout << "* ������2j������������ϰ���ճ��Ͽεĵط���" << endl;
    if (a == 8)
        cout << "* ������1j������������ϰ���ճ��Ͽεĵط���" << endl;
    if (a == 9)
        cout << "* ������3j������������ϰ���ճ��Ͽεĵط���" << endl;
    if (a == 10)
        cout << "* ������4j������������ϰ���ճ��Ͽεĵط���" << endl;
    if (a == 11)
        cout << "* ������ѧУ�����ݣ������ڵ����򳡺���ë�򳡣�" << endl;
    if (a == 12)
        cout << "* ������6j������������ϰ���ճ��Ͽεĵط���" << endl; 
    if (a == 13)
        cout << "* ���������ϢѧԺ��" << endl; 
    if (a == 14)
        cout << "* ��֯���װѧԺ��" << endl;
    if (a == 15)
        cout << "* ����ԴȪ��������ѧУ�ĵر꣡" << endl;
    if (a == 16)
        cout << "* С���ţ�����ѧ������ܽ������Ժܶ�ѧ��������ѡ��������ţ�" << endl;
}
void Query1()
{
    int a, b, c;
    cout << "======���з�ʽ=====" << endl;
    cout << "1.����." << endl;
    cout << "2.�ݳ�." << endl;
    cout << "=================" << endl;
    cout << "�������ѡ��(1 or 2)��";
    cin >> a;
    cout << "��������ţ�";
    cin >> b;
    cout << "�����յ��ţ�";
    cin >> c;
    if (b <= 0 && b > 20 || c <= 0 && c > 20)
        cout << "������󣬾��㲻���ڡ�" << endl;
    else
        dijstra(b, a, c);
}
void DIS(int a, int b, int c)//����dis����
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
        cout << "û��ֱ���·����ѡ���С�" << endl;
    else
    {
        cout << "��" << b << "��" << c << "�����·��Ϊ��";
        while (!S.empty())
        {
            if (S.size() > 1)
                cout << S.top() << "->";
            else
                cout << S.top();
            S.pop();
        }
        cout << endl << "����̾���Ϊ��" << dis[c] << endl;
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
    cout << "======���з�ʽ=====" << endl;
    cout << "    1.����." << endl;
    cout << "    2.�ݳ�." << endl;
    cout << "===================" << endl;
    cout << "�������ѡ��(1 or 2)��";
    cin >> a;
    cout << "��������ţ�";
    cin >> b;
    cout << "�����յ��ţ�";
    cin >> c;
    // ���� ��������
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
        cout << "���������ϣ���3������ֻ���ǰ�����϶̵�·��:" << endl;
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
        cout << "û��ֱ��������·��!!!" << endl;

}

void QQ(int a)
{
    int i, j, k, flag1 = 0;
    // ���� ��������
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
                cout << "·��Ϊ��";
                for (j = 0; j < m; j++)
                    // while(!dd.front().empty())
                {
                    cout << dd.front().front() << " ";
                    dd.front().push_back(dd.front().front());
                    dd.front().pop_front();
                }
                cout << aa[e - 1] << " ";
                cout << endl;
                //cout<<"��·������Ϊ��"<<dis[aa[e-1]]<<endl;
            }
            dd.push_back(dd.front());
            dd.pop_front();
        }

    }if (flag1 == 0)
        cout << "**������������·��" << endl;
}
void Query3()
{
    init();
    int a;
    memset(aa, 0, sizeof(aa));
    memset(flag, 0, sizeof(flag));
    cout << "======���з�ʽ=====" << endl;
    cout << "    1.����." << endl;
    cout << "    2.�ݳ�." << endl;
    cout << "===================" << endl;
    cout << "�������ѡ��(1 or 2)��";
    cin >> a;
    cout << "���뾭���ĵ㣨��0����,Ĭ�Ͽ�ʼΪ��ʼ�㣩��";
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
    cout << "======================================������ƽ��ͼ==================================" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "|                                               | 1.���� |--------------------------|" << endl;
    cout << "|                          ----------            |      |                           |" << endl;
    cout << "|                          | 4.�Ľ� |-------------      ----------------------------|" << endl;
    cout << "|              --------    ----------   |                                   |       |" << endl;
    cout << "|              | 5.A��|       ----------   |                                |  3    |" << endl;
    cout << "|              --------       | 7.���� |---                                 | ͼ���|" << endl;
    cout << "|              | 6.B��|       ----------   |           -----------          |       |" << endl;
    cout << "|  --------    --------       ----------   |           |   15    |          --------|" << endl;
    cout << "|  |10.���|   |13.C��|       | 9.���� |---|-----------| ԴȪ����|------------------|" << endl;
    cout << "|  --------    --------       ----------   |           |         |        | 8.һ�� ||" << endl;
    cout << "|  |12.����|   |14.D��|                                 -----------       --------- |" << endl;
    cout << "|  --------    --------                                                             |" << endl;
    cout << "|                        -----------           ---------------                      |" << endl;
    cout << "|                        |11.������ |         |               |                     |" << endl;
    cout << "|                        |          |         |   2.�ٳ�      |                     |"<< endl;
    cout << "|                        -----------          |               |                     |" << endl;
    cout << "|                                             |               |                     |" << endl;
    cout << "|                                              ---------------                      |" << endl;
    cout << "|                                                                |16.С����|        |" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

}
void menu()
{
    int a;
    init();
    while (1)
    {
        cout << "============�˵�============" << endl;
        cout << "0.�˳�." << endl;
        cout << "1.��ѯ���о�����Ϣ." << endl;
        cout << "2.��ѯ����������·��." << endl;
        cout << "3.��ѯ�����������·��." << endl;
        cout << "4.��ѯ�ྰ������·��." << endl;
        cout << "5.���չ��̴�ѧƽ��ͼ." << endl;
        cout << "===========================" << endl;
        cout << "�������ѡ��(0 ~ 5)��";
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