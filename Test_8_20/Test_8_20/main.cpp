//
//  main.cpp
//  Test_8_20
//
//  Created by zht on 2023/8/20.
//

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<TreeNode*> allPossibleFBT(int n)
    {
        vector<TreeNode*> ret;
        //排除不符合的情况
        if(n % 2 == 0) return ret;//如果是偶数的情况，直接返回空
        //递归出口
        if(n == 1)
        {
            ret.push_back(new TreeNode);
            return ret;
        }
        //函数体内部
        //跟节点用掉n中的一个，剩下n-1个左右子树分
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        for(int i = 1; i < n - 2; i += 2)
        {
            left = allPossibleFBT(i);
            right = allPossibleFBT(n-1-i);
        }
        for(auto& le : left)
        {
            for(auto& re : right)
            {
                TreeNode* root = new TreeNode;
                root->left = le;
                root->right = re;

                ret.push_back(root);
            }
        }
        return ret;
    }
};


int main()
{
    vector<TreeNode*> ret = Solution().allPossibleFBT(7);
    
    return 0;
}
