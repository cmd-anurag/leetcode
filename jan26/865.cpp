#include<unordered_map>
#include<vector>
using std::unordered_map, std::vector;
using std::max;

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, int> nodeDepth;

        populateDepths(root, 0, nodeDepth);
        vector<TreeNode*> deepestLeaves;
        int maxDepth = 0;

        for(auto &pair : nodeDepth) {
            maxDepth = max(pair.second, maxDepth);
        }

        for(auto &pair : nodeDepth) {
            if(pair.second == maxDepth) {
                deepestLeaves.push_back(pair.first);
            }
        }

        return solve(deepestLeaves, 0, root);

        return nullptr;
    }

    TreeNode* solve(vector<TreeNode*> &deepestLeaves, int i, TreeNode* &root) {
        if(i == deepestLeaves.size() - 1) return deepestLeaves[i];

        return LCA(root, deepestLeaves[i], solve(deepestLeaves, i+1, root));
    }

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(root == p) return p;
        if(root == q) return q;

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);

        if(left && right) {
            return root;
        }

        if(left) return left;
        if(right) return right;

        return nullptr;
    }

    void populateDepths(TreeNode* root, int depth, unordered_map<TreeNode*, int> &nodeDepth) {
        if(!root) return;

        nodeDepth[root] = depth;

        populateDepths(root->left, depth + 1, nodeDepth);
        populateDepths(root->right, depth + 1, nodeDepth);
    }
};