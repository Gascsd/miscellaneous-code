//
//  main.cpp
//  Test_5_7
//
//  Created by zht on 2023/5/7.
//
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void InOrderConvert(TreeNode* cur, TreeNode*& prev)
    {
        if(cur == nullptr)//空树直接返回
            return;

        InOrderConvert(cur->left, prev);

        //中序操作
        cur->left = prev;//连接左结点
        if(prev)//连接右节点
            prev->right = cur;

        prev = cur;//交替向后走遍历所有节点

        InOrderConvert(cur->right, prev);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* prev = nullptr;
        InOrderConvert(pRootOfTree, prev);//重新连接节点

        TreeNode* head = pRootOfTree;
//        cout << head << " " << head->left << endl;
        while(head && head->left)//中序遍历的流程拿到最左节点
        {
//            cout <<"head->val" << head->val << endl;
            head = head->left;
//            cout <<"head->left->val" << head->left->val << endl;
        }
            
        return head;
    }
};



int main()
{
    TreeNode* node1 = new TreeNode(10);
    TreeNode* node2 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(14);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(8);
    TreeNode* node6 = new TreeNode(12);
    TreeNode* node7 = new TreeNode(16);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    TreeNode* head = Solution().Convert(node1);
    TreeNode* cur = head;
    while(cur)
    {
        cout << cur->val << ' ';
        cur = cur->right;
    }
    cout << endl;
    return 0;
}
