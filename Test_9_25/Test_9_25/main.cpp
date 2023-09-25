//
//  main.cpp
//  Test_9_25
//
//  Created by zht on 2023/9/25.
//

#include <iostream>
using namespace std;


class Solution {
public:
    //2,0,2,1,1,0
    void sortColors(vector<int>& nums) {
        int left = 0,i = 0, right = nums.size();
        while(i < right)
        {
            if(nums[i] == 0)
            {
                swap(nums[i++], nums[left++]);
            }
            else if(nums[i] == 1)
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[--right]);
            }
        }
    }
};

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    Solution().sortColors(nums);
    for(auto& e : nums)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
