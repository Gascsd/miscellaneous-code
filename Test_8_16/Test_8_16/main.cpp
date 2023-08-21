//
//  main.cpp
//  Test_8_16
//
//  Created by zht on 2023/8/16.
//

#include <iostream>
using namespace std;


//Definition for singly-linked list.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode;
        dfs(head, l1, l2, 0);
        return head->next;
    }
    void dfs(ListNode* cur, ListNode* l1, ListNode* l2, int add)
    {
        if(l1 == nullptr && l2 == nullptr && add == 0) return;
        int tmp = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + add;
        add = tmp / 10;
        cur->next = new ListNode(tmp % 10);
        if(l1 != nullptr && l2 != nullptr)
            dfs(cur->next, l1->next, l2->next, add);
        else if(l1 == nullptr && l2 != nullptr)
            dfs(cur->next, nullptr, l2->next, add);
        else if(l2 == nullptr && l1 != nullptr)
            dfs(cur->next, l1->next, nullptr, add);
        else
            dfs(cur->next, nullptr, nullptr, add);
    }
};

int main()
{
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    ListNode* head = Solution().addTwoNumbers(l1, l2);
    
    while(head && head->next)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
