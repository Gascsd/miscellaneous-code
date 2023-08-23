//
//  main.cpp
//  Test_8_17
//
//  Created by zht on 2023/8/17.
//

#include <iostream>
using namespace std;

class Solution1
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> ret;
        if(expression.empty()) return ret;

        vector<int> Lret;
        vector<int> Rret;
        for(int i = 0; i < expression.size(); ++i)
        {
            if(!isdigit(expression[i]))//是运算符
            {
                //分成左右两边拿到结果集，进行处理
                Lret = diffWaysToCompute(expression.substr(0, i));
                Rret = diffWaysToCompute(expression.substr(i + 1));
                for(auto& left : Lret)
                {
                    for(auto& right : Rret)
                    {
                        ret.push_back(left + right);
                        ret.push_back(left - right);
                        ret.push_back(left * right);
                    }
                }
            }
        }
        if(ret.empty())
        {
            ret.push_back(stoi(expression));
        }
        return ret;
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n == 1) return 1;

        int ret = findTheWinner(n-1, k);
        if(k > n) k %= n;
        int curLoser = k;

        if(ret < curLoser)
        {
            return ret;
        }
        else
        {
            return ret + 1;
        }
    }
};

int main()
{
    int ret = Solution().findTheWinner(5, 2);
    cout << ret << endl;
    return 0;
}
