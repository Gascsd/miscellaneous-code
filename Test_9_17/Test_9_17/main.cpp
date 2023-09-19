//
//  main.cpp
//  Test_9_17
//
//  Created by zht on 2023/9/17.
//

#include <iostream>
#include <queue>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val = 0) : val(_val), left(nullptr), right(nullptr) {}
};
vector<int> InorderT(TreeNode* root)
{
    vector<int> ret;
    queue<TreeNode*> q;
    if(root != nullptr) q.push(root);
    
    while(!q.empty())
    {
        TreeNode* t = q.front();
        q.pop();
        ret.push_back(t->val);
        if(t->left != nullptr) q.push(t->left);
        if(t->right != nullptr) q.push(t->right);
    }
    
    
    return ret;
}



//int main()
//{
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(7);
//
//    vector<int> ret = InorderT(root);
//    for(auto& e : ret)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//    return 0;
//}

#include "test.hpp"

int main()
{
    main_1();
    return 0;
}

