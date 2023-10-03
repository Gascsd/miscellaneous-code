//
//  test1.cpp
//  Test_10_2
//
//  Created by zht on 2023/10/2.
//
#include <iostream>
#include <vector>
using namespace std;

//C++的类型转换（标准的）
//1. static_cast  ==> C语言中的隐式类型转换
//2. reinterpret_cast ==> C语言的强制类型转换
//3. const_cast ==> 把一个const类型转换成非const类型
//4. dynamic_cast ==> 检测子类（派生类）和父类（基类）之间的转换的


void test1()
{
    double d = 12.34;
    int i = static_cast<int>(d);
    int* pi = reinterpret_cast<int*>(i);
    //int p = reinterpret_cast<int>(pi);
    cout << i << " " << pi << endl;
    volatile const int a = 10;
    int* pa = const_cast<int*>(&a);
    *pa = 20;
    cout << *pa << " " << a << endl;
}

class Solution
{
public:
    int search(vector<int>& nums, int target) 
    {
        size_t begin = 0, end = nums.size() - 1;
        
        while(begin <= end)
        {
            size_t mid = (begin + end) / 2;
            if(nums[mid] == target)
            {
                return static_cast<int>(mid);
            }
            else if(nums[mid] > target)
            {
                //[begin, mid-1]
                end = mid - 1;
            }
            else
            {
                //[mid+1, end]
                begin = mid + 1;
            }
        }
        return -1;
    }
};

class Solution1
{
public:
    void moveZeroes(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
            {
                for(int j = i; j < nums.size(); ++j)
                {
                    swap(nums[j], nums[j+1]);
                }
                i--;
            }
        }
    }
};

int main_1()
{
    vector<int> v = {0,1,0,3,12};
    Solution1().moveZeroes(v);
    //test1();
    return 0;
}
