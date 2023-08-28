//
//  main.cpp
//  Test_8_24
//
//  Created by zht on 2023/8/24.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* dfs(ListNode* l1, ListNode* l2, int add)
    {
        if(l1 == nullptr && l2 == nullptr && add == 0) return nullptr;
        
        ListNode* newHead;
        if(l1 != nullptr && l2 != nullptr)
        {
            int tmp = l1->val + l2->val + add;
            add = tmp / 10;
            tmp %= 10;
            newHead = new ListNode(tmp);
            newHead->next = dfs(l1->next, l2->next, add);
        }
        else if(l1 != nullptr && l2 == nullptr)
        {
            int tmp = l1->val + add;
            add = tmp / 10;
            tmp %= 10;
            newHead = new ListNode(tmp);
            newHead->next = dfs(l1->next, nullptr, add);
        }
        else if(l1 == nullptr && l2 != nullptr)
        {
            int tmp = l2->val + add;
            add = tmp / 10;
            tmp %= 10;
            newHead = new ListNode(tmp);
            newHead->next = dfs(nullptr, l2->next, add);
        }
        else if(l1 == nullptr && l2 == nullptr)
        {
            int tmp = add;
            add = tmp / 10;
            newHead = new ListNode(tmp);
            newHead->next = dfs(nullptr, nullptr, add);
        }
        return newHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        return dfs(l1, l2, 0);
    }
};

int main()
{
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    
    ListNode* l2 = new ListNode(9);
    
    ListNode* ret = Solution().addTwoNumbers(l1, l2);
    while(ret)
    {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;
    return 0;
}
