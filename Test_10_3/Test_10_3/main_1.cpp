//
//  main_1.cpp
//  Test_10_3
//
//  Created by zht on 2023/10/3.
//

#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        srand(time(NULL));
        qsort(nums, 0, static_cast<int>(nums.size()) - 1);
        return nums;
    }
    void qsort(vector<int>& nums, int begin, int end)
    {
        if(begin >= end) return;

        int i = begin, left = begin, right = end;
        int key = GetRandom(nums, begin, end);
        while(i <= right)
        {
            if(nums[i] < key)
            {
                swap(nums[left], nums[i]);
                left++;
                i++;
            }
            else if(nums[i] == key)
            {
                i++;
            }
            else//  >key
            {
                swap(nums[right], nums[i]);
                right--;
            }
        }
        qsort(nums, begin, left - 1);
        qsort(nums, right + 1, end);
    }
    int GetRandom(vector<int>& nums, int left, int right)
    {
        return nums[static_cast<int>(rand())%(right - left + 1) + left];
    }
};

class Solution1
{
public:
    int qfind(vector<int>& nums,int begin,int end,int k)
    {
        if(end == begin)//函数递归出口
        {
            return nums[end];
        }
        //边界设置
        int left = begin, i = begin, right = end;
        int key = nums[rand() % (end - begin + 1) + begin];
        //数组分三段
        while(i <= right)
        {
            if(nums[i] < key)
            {
                swap(nums[left++],nums[i++]);
            }
            else if(nums[i] == key)
            {
                i++;
            }
            else //if(nums[i] > key)
            {
                swap(nums[right--],nums[i]);
            }
        }
        //求出每一段的长度
        //int a = left - begin;
        int b = right - left + 1;
        int c = end - right;
        //判断k落在哪个位置
        if(c >= k)
        {
            return qfind(nums, right + 1, end, k);
        }
        else if(k <= b + c)
        {
            return key;
        }
        else
        {
            return qfind(nums, begin, left - 1, k - b - c);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return qfind(nums,0,static_cast<int>(nums.size() - 1), k);
    }
};

int main_1()
{
    int k = 1;
    vector<int> nums = {2, 1};
    int ret = Solution1().findKthLargest(nums, k);
    cout << ret << endl;
//    for(auto& e : nums)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
    return 0;
}
