#define _CRT_SECURE_NO_WARNINGS 1
//Fibonacci数列
//#include <iostream>
//using namespace std;
//int GetMin(int x, int y)
//{
//    return x < y ? x : y;
//}
//int main()
//{
//    int n;
//    cin >> n;
//    int a, b, c;
//    a = 0;
//    b = 1;
//    c = 1;
//    while (c < n)
//    {
//        a = b;
//        b = c;
//        c = a + b;
//    }
//    int ret = GetMin(c - n, n - b);
//    cout << ret << endl;
//    return 0;
//}

//合法括号序列判断
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        stack<char> sk;
        for (auto e : A)
        {
            if (e == '(')
                sk.push(e);
            else if (e == ')')
            {
                if (!sk.empty())
                    sk.pop();
                else
                    return false;
            }
            else
                return false;
        }
        if (sk.empty())
            return true;
        else
            return false;
    }
};


int main()
{
    string A;
    cin >> A;
    int n;
    cin >> n;
    bool ret = Parenthesis().chkParenthesis(A, n);
    if (ret == false)
        cout << "false" << endl;
    else
        cout << "true" << endl;
	return 0;
}