//
//  main.cpp
//  Test_10_5
//
//  Created by zht on 2023/10/5.
//

#include <iostream>
#include <vector>
using namespace std;
//class Solution
//{
//public:
//    vector<int> tmp;
//    int reversePairs(vector<int>& nums)
//    {
//        tmp.resize(nums.size() - 1);
//        return mergeSort(nums, 0, nums.size() - 1);
//    }
//    int mergeSort(vector<int>& nums, int left, int right)
//    {
//        if(left >= right) return 0;
//
//        int mid = (left + right) >> 1;
//        int ret = 0;
//        ret += mergeSort(nums, left, mid);
//        ret += mergeSort(nums, mid+1, right);
//
//        //1. 统计翻转对数量
//        int cur1 = left, cur2 = mid + 1, i = left;
//        while(cur1 <= mid)
//        {
//            while(cur2 <= right && nums[cur2] >= nums[cur1] / 2.0)
//            {
//                cur2++;
//            }
//            if(cur2 > right) break;
//            ret += right - cur2 + 1;
//            cur1++;
//        }
//
//        //2. 合并两个有序数组
//        cur1 = left, cur2 = mid + 1;
//        while(cur1 <= mid && cur2 <= right)
//        {
//            if(nums[cur1] <= nums[cur2])
//            {
//                tmp[i++] = nums[cur2++];
//            }
//            else
//            {
//                tmp[i++] = nums[cur1++];
//            }
//        }
//        while(cur1 <= mid) tmp[i++] = nums[cur1++];
//        while(cur2 <= right) tmp[i++] = nums[cur2++];
//        for(int i = left; i <= right; ++i)
//        {
//            nums[i] = tmp[i];
//        }
//        return ret;
//    }
//};


class Solution
{
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int five = 0, ten = 10;
        for(auto& x : bills)
        {
            if(x == 5)
            {
                five++;
            }
            else if(x == 10)
            {
                if(five == 0) return false;
                else
                {
                    five--;
                    ten++;
                }
            }
            else //20
            {
                if(ten && five)//贪心体现在先找零的是10的
                {
                    ten--;
                    five--;
                }
                else if(five >= 3)
                {
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};

void test11()
{
    vector<int> v = {5,5,5,10,5,5,10,20,20,20};
    //int ret = Solution().reversePairs(v);
    auto ret = Solution().lemonadeChange(v);
    cout << ret << endl;
}
int main_1();
int main()
{
    main_1();
    return 0;
}
