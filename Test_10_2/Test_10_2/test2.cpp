//
//  test2.cpp
//  Test_10_2
//
//  Created by zht on 2023/10/2.
//

#include <iostream>
#include <vector>
using namespace std;

//typedef unsigned int size_t;

int GetRandom(vector<int>& nums, int left, int right)
{
    //cout <<rand() % (right - left + 1) + left << endl;
    //return nums[rand() % (right - left + 1) + left];
    
    int mid = (left + right) / 2;
    if(nums[left] > nums[right])
    {
        if(nums[left] > nums[mid])
        {
            return nums[right] > nums[mid] ? nums[right] : nums[mid];
        }
        else
        {
            return nums[left];
        }
    }
    else//nums[left] < nums[right]
    {
        if(nums[left] > nums[mid])
        {
            return nums[left];
        }
        else
        {
            return nums[right] > nums[mid] ? nums[right] : nums[mid];
        }
    }
}

void qsort(vector<int>& nums, int begin, int end)
{
    if(begin > end) return;//区间不存在的时候
    //算法导论
    int key = GetRandom(nums, begin, end);
    int left = begin, i = begin, right = end;
    while(i <= right)
    {
        if(nums[i] > key)
        {
            swap(nums[i], nums[right--]);
        }
        else if(nums[i] == key)
        {
            i++;
        }
        else
        {
            swap(nums[left++], nums[i++]);
        }
    }
    //排序小于key和大于key的区间
    //[begin, left-1][left, right][right + 1, end]
    qsort(nums, begin, left - 1);
    qsort(nums, right + 1, end);
}

class Solution {
public:
    vector<int> v;
    vector<int> sortArray(vector<int>& nums) {
        v.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return v;
    }
    void mergeSort(vector<int>& nums, int begin, int end)
    {
        if(begin > end) return;
        int mid = (begin + end) >> 1;
        //[begin, mid] [mid+1, end]
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid+1, end);
        int cur1 = begin, cur2 = mid+1, i = 0;
        while(cur1 <= mid && cur2 <= end)
        {
            v[i++] = nums[cur1] < nums[cur2] ? nums[cur1++] : nums[cur2++];
        }
        while(cur1 <= mid) v[i++] = nums[cur1++];
        while(cur2 <= end) v[i++] = nums[cur2++];
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        //1. 排序O(NlogN);
        //2. 建堆O(NlogK)
        //3. 快速选择O(N)
        return qselect(nums, 0, nums.size() - 1, k);
    }
    int qselect(vector<int>& nums, int begin, int end, int k)
    {
        if(begin > end) return -1;
        int key = GetRandom(nums, begin, end);
        int left = begin, i = begin, right = end;
        while(i < right)
        {
            if(nums[i] < key)
            {
                swap(nums[left++], nums[i++]);
            }
            else if(nums[i] == key)
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[right--]);
            }
        }
        //分情况讨论
        int a = left - begin, b = right - left, c = end - right + 1;
        if(k < c)
        {
            return qselect(nums, right, end, k);
        }
        else if(k <= b + c)
        {
            return key;
        }
        else
        {
            return qselect(nums, begin, left - 1, k - b - c);
        }
    }
    int GetRandom(vector<int>& nums, int begin, int end)
    {
        return nums[rand() % (end - begin + 1) + begin];
    }
};

int main_2()
{
    //srand(time(NULL));
    vector<int> v = {5,2,3,1};
    auto ret = Solution().sortArray(v);
    for(auto& e : ret)
    {
        cout << e << " ";
    }
    cout << endl;
//    vector<int> vv;
//    for(int i = 0; i < 60; ++i)
//    {
//        auto ret = Solution().findKthLargest(v, 4);
//        vv.push_back(ret);
//    }
//    for(auto& e : vv)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
    return 0;
}
