//
//  main.cpp
//  Test_10_11
//
//  Created by zht on 2023/10/11.
//

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> strs;
        priority_queue<string, vector<string>, less<string>> pqs;
        for(auto& e : nums)
        {
            string tmp = to_string(e);
            cout << tmp << endl;
            pqs.push(tmp);
        }
        string ret;
        while(pqs.empty())
        {
            ret += pqs.top();
            cout << pqs.top() << endl;
            pqs.pop();
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = {10, 2};
    auto ret = Solution().largestNumber(nums);
    cout << ret << endl;
    return 0;
}


void* memset(void* ptr, int val, size_t len)
{
    char* tmp = (char*)ptr;
    while(len--)
    {
        *tmp++ = val;
    }
    return ptr;
}
