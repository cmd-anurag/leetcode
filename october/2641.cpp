#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);

        vector<int> sums;
        int sum;
        while(!q.empty()) {
            sum = 0;
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                TreeNode* front = q.front();
                q.pop();
                sum += front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            sums.push_back(sum);
        }

        q.push(root);
        root->val = 0;
        int level = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                TreeNode* front = q.front();
                q.pop();
                int originalLeft = 0;
                int originalRight = 0;

                if(front->left) {
                    originalLeft = front->left->val;
                }
                if(front->right) {
                    originalRight = front->right->val;
                }


                if(front->left && front->right) {
                    front->left->val = sums.at(level) - originalLeft - originalRight;
                    front->right->val = sums.at(level) - originalLeft - originalRight;
                    q.push(front->left);
                    q.push(front->right);
                } 
                else if(front->right) {
                    front->right->val = sums.at(level) - originalRight;
                    q.push(front->right);
                }
                else if(front->left) {
                    front->left->val = sums.at(level) - originalLeft;
                    q.push(front->left);
                }
            }

            ++level;
        }
        return root;
    }
};

int main() {
    
}