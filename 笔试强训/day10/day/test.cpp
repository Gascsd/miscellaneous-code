//¾®×ÖÆå
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Board {
//public:
//    bool checkWon(vector<vector<int>> board) {
//        // write code here
//        int* sum = new int[4];
//        for (size_t i = 0; i < board.size(); ++i)
//        {
//            memset(sum, 0, sizeof(int) * 4);
//            for (size_t j = 0; j < board[i].size(); ++j)
//            {
//                sum[0] += board[i][j];//ÅÐ¶Ïºá
//                sum[1] += board[j][i];//ÅÐ¶ÏÊú
//            }
//            if ((sum[0] == board[i].size()) || sum[1] == board[i].size())
//                return true;
//        }
//        memset(sum, 0, sizeof(int) * 4);
//        for (size_t i = 0; i < board.size(); ++i)
//        {
//            sum[2] += board[i][i];//ÅÐ¶ÏÖ÷¶Ô½ÇÏß
//            sum[3] += board[i][board[i].size() - i - 1];//ÅÐ¶Ï¸±¶Ô½ÇÏß
//            if ((sum[2] == board[i].size()) || sum[3] == board[i].size())
//                return true;
//        }
//        return false;
//    }
//};
//
//int main()
//{
//    vector<vector<int>> board;
//    board.resize(3);
//    board[0] = { 1,0,1 };
//    board[1] = { 1,-1,-1 };
//    board[2] = { 1,-1,0 };
//    bool ret = Board().checkWon(board);
//    if (ret == false)
//        cout << "false" << endl;
//    else
//        cout << "true" << endl;
//    return 0;
//}

//ÃÜÂëÇ¿¶ÈµÈ¼¶
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string passwd;
    cin >> passwd;
    int val = 0;
    //ÃÜÂë³¤¶È
    size_t len = passwd.size();
    if (len <= 4)
        val += 5;
    else if (len >= 5 && len <= 7)
        val += 10;
    else if (len >= 8)
        val += 25;
    //×ÖÄ¸¡¢Êý×Ö¡¢·ûºÅ
    bool upper = false, lower = false;
    int count_asc = 0, count_num = 0;
    for (auto e : passwd)
    {
        if (e >= 'A' && e <= 'Z')
            upper = true;
        if (e >= 'a' && e <= 'z')
            lower = true;
        if (e >= '0' && e <= '9')
            count_num++;
        if ((e >= 0x21 && e <= 0x2F)
            || (e >= 0x3A && e <= 0x40)
            || (e >= 0x5B && e <= 0x60)
            || (e >= 0x7B && e <= 0x7E))
            count_asc++;
    }
    if (upper && lower)
        val += 20;
    else if (!(upper || lower))
        val += 0;
    else
        val += 10;

    if (count_num == 1)
        val += 10;
    else if (count_num > 1)
        val += 20;

    if (count_asc == 1)
        val += 10;
    else if (count_asc > 1)
        val += 25;
    //½±Àø
    if (upper && lower && count_num && count_asc)
        val += 5;
    else if ((upper || lower) && count_num && count_asc)
        val += 3;
    else if ((upper || lower) && count_num)
        val += 2;


    if (val >= 90)
        cout << "VERY_SECURE" << endl;//
    else if (val >= 80)
        cout << "SECURE" << endl;//
    else if (val >= 70)
        cout << "VERY_STRONG" << endl;
    else if (val >= 60)
        cout << "STRONG" << endl;//
    else if (val >= 50)
        cout << "AVERAGE" << endl;//
    else if (val >= 25)
        cout << "WEAK" << endl;//
    else if (val >= 0)
        cout << "VERY_WEAK" << endl;//
    return 0;
}

