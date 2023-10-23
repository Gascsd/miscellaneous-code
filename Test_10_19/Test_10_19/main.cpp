//
//  main.cpp
//  Test_10_19
//
//  Created by zht on 2023/10/19.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            int Max = 0;
            for (int j = i; j >= 0; --j)
            {
                if (nums[i] > nums[j])
                {
                    Max = max(dp[j], Max);
                }
            }
            dp[i] = Max;
        }
        int ret = dp[0];
        for (int i = 1; i < dp.size(); ++i)
        {
            ret = max(ret, dp[i]);
        }
        for(auto& e : dp)
        {
            cout << e << " ";
        }
        cout << endl;
        return ret;
    }
};

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    auto ret = Solution().lengthOfLIS(nums);
    cout << ret << endl;
    return 0;
}
