//洗牌
//#include <iostream>
//#include <list>
//using namespace std;
//list<int> shuffle_poker(list<int>& lt)
//{
//    list<int>::iterator first = lt.begin();
//    list<int>::iterator second = lt.begin();
//    size_t n = lt.size() / 2;
//    while (n--)
//    {
//        ++second;
//    }
//    list<int> ret;
//    while (second != lt.end())
//    {
//        lt.push_back(*first);
//        lt.push_back(*second);
//        ++first;
//        ++second;
//    }
//    return ret;
//}
//int main()
//{
//    int t = 0;
//    cin >> t;
//    while (t--)
//    {
//        int n, k;
//        cin >> n >> k;
//        list<int> lt;
//        for (int i = 0; i < 2 * n; ++i)
//        {
//            int val;
//            cin >> val;
//            lt.push_back(val);
//        }
//        list<int> ret = lt;
//        while (k)
//        {
//            k--;
//            ret = shuffle_poker(ret);
//        }
//        for (auto e : ret)
//        {
//            cout << e << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

//MP3光标位置
#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string cmd;
    cin >> cmd;
    list<int> lt;
    for (int i = 1; i <= n; ++i)
    {
        lt.push_back(i);
    }
    list<int>::iterator start = lt.begin();
    list<int>::iterator end = start;
    list<int>::iterator flag = start;
    for (int i = 0; i < 3; i++)
    {
        ++end;
    }
    //读取命令，进行操作
    for (auto e : cmd)
    {
        if (e == 'U')
        {
            if (flag == lt.begin())//当光标在第一首歌的时候按up
            {
                end = --lt.end();
                start = end;
                for (int i = 0; i < 3; i++)
                {
                    --start;
                }
                flag = end;
            }
            else if (flag == start)//在当前页面的最上端的时候按up
            {
                --start;
                --end;
                --flag;
            }
            else
            {
                --flag;
            }
        }
        else//按Down的时候
        {
            if (flag == --lt.end())//当在最后一首歌的时候按Down
            {
                start = lt.begin();
                end = start;
                for (int i = 0; i < 3; i++)
                {
                    ++end;
                }
                flag = start;
            }
            else if (flag == end)//在当前页面最下端的时候按Down
            {
                ++start;
                ++end;
                ++flag;
            }
            else
            {
                ++flag;
            }
        }
    }
    ++end;
    if (lt.size() <= 4)
    {
        for (auto e : lt)
        {
            cout << e << " ";
        }
    }
    else
    {
        while (start != end)
        {
            cout << *start << " ";
            ++start;
        }
    }
    cout << endl;
    cout << *flag << endl;
    return 0;
}