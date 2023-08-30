//
//  main.cpp
//  Test_8_30
//
//  Created by zht on 2023/8/29.
//

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val = 0) :val(_val), left(nullptr), right(nullptr) {}
};
//
//int main()
//{
//    int n;
//    cin >> n;
//    TreeNode* array = new TreeNode[n];
//    array[0].val = 0;
//    for(int i = 0; i < n; ++i)
//    {
//        int left,right;
//        cin >> left >> right;
//        array[i].left = array[2 * i + 1];
//        array[i].right = array[2 * i + 2];
//        array[2 * i + 1].val = left;
//        array[2 * i + 2].val = right;
//    }
//
//    return 0;
//}


#include <stack>
#include <queue>

#include "stack.h"
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(int x = 0)
//    {
//        val = x;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//void Test()
//{
//    my::stack<int> st;
//    st.push(1);
//    st.push(2);
//    st.push(3);
//    st.push(4);
//    st.push(5);
//    st.push(6);
//    st.push(7);
//    cout << "size:" << st.size() << endl;
//    while(!st.empty())
//    {
//        cout << st.top() << " ";
//        st.pop();
//    }
//    cout << endl;
//}
//
//void Test2()
//{
//    my::queue<int> q;
//    q.push(1);
//    q.push(2);
//    q.push(3);
//    q.push(4);
//    q.push(5);
//    q.push(6);
//    q.push(7);
//    cout << "size:" << q.size() << endl;
//    while(!q.empty())
//    {
//        cout << q.front() << " ";
//        q.pop();
//    }
//    cout << endl;
//}
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
//    queue<TreeNode*> q;
//    if(root != nullptr)
//    {
//        q.push(root);
//    }
//    vector<int> ret;
//    while(!q.empty())
//    {
//        TreeNode* tmp = q.front();
//        ret.push_back(tmp->val);
//        q.pop();
//        if(tmp->left)
//            q.push(tmp->left);
//        if(tmp->right)
//            q.push(tmp->right);
//    }
//    for(auto& e : ret)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//
//    //Test1();
//    //Test2();
//    return 0;
//}


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        queue<TreeNode*> q;
        vector<TreeNode*> v;
        int maxWidth = 0;
        q.push(root);
        int levelSize = 1;
        while(!q.empty())
        {
            while(levelSize--)
            {
                TreeNode* r = q.front();
                q.pop();
                v.push_back(r);
                if(r->left) q.push(r->left);
                else q.push(nullptr);
                if(r->right) q.push(r->right);
                else q.push(nullptr);
            }
            //找左端点
            int pos1 = -1, pos2 = -1;
            for(int i = 0;i < v.size(); ++i)
            {
                if(v[i] != nullptr)
                {
                    pos1 = i;
                    break;
                }
            }
            //找右端点
            for(int i = v.size()-1;i >= 0; --i)
            {
                if(v[i] != nullptr)
                {
                    pos2 = i;
                    break;
                }
            }
            v.clear();
            levelSize = q.size();
            if(pos1 == -1 || pos2 == -1) break;
            cout << maxWidth << endl;
            maxWidth = max(pos2 - pos1 + 1, maxWidth);
        }
        return maxWidth;
    }
};

void func(int n)
{
    if(n == 0) return;
    func(n+1);
}
void prevOrder(TreeNode* root)
{
    if(root == nullptr) return;
    
    cout << root->val << " ";
    prevOrder(root->left);
    prevOrder(root->right);
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    prevOrder(root);
    //func(1);
    return 0;
}
