//
//  main.cpp
//  Test_8_29
//
//  Created by zht on 2023/8/29.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
        
    }
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool evaluateTree(TreeNode* root)
    {
        if(root == nullptr) return false;
        if(root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
        else if(root->val == 3) return evaluateTree(root->left) &&  evaluateTree(root->right);
        else return root->val;
    }
};

int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    
    bool ret = Solution().evaluateTree(root);
    
    return 0;
}
