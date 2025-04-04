#include<bits/stdc++.h>

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
    pair<TreeNode *, int> dfs(TreeNode *root)
    {
        if (!root)
        {
            return {nullptr, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // both subtree having same height
        // root will be the LCA
        if (left.second == right.second)
        {
            return {root, left.second + 1};
        }
        else if (left.second > right.second)
        {
            // left subtree has a greater height so its LCA will be picked
            return {left.first, left.second + 1};
        }
        else
        {
            // right subtree has a greater height so its LCA will be picked
            return {right.first, right.second + 1};
        }
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return dfs(root).first;
    }
};