//
//  main.cpp
//  Test_10_14
//
//  Created by zht on 2023/10/14.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums)
    {
        int m = nums.size(), n = nums[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
            {
                if(nums[i][j] == 1)
                {
                    //遇到障碍物
                    dp[i][j] = 0;
                }
                else
                {
                    //没有遇到障碍物
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        return dp[m][n];
    }
};

int main()
{
    vector<vector<int>> nums = {{0,0,0},{0,1,0},{0,0,0}};
    auto ret = Solution().uniquePathsWithObstacles(nums);
    cout << ret << endl;
    return 0;
}
