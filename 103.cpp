#include <vector>
#include <stack>
using std::vector;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        std::stack<TreeNode *> s1;
        std::stack<TreeNode *> s2;

        s1.push(root);

        vector<vector<int>> result;

        while (!s1.empty() || !s2.empty())
        {
            vector<int> temp;
            while (!s2.empty())
            {
                TreeNode *top = s2.top();
                s2.pop();
                temp.push_back(top->val);
                if (top->right)
                {
                    s1.push(top->right);
                }

                if (top->left)
                {
                    s1.push(top->left);
                }
            }
            if (!temp.empty())
            {
                result.push_back(temp);
                temp.clear();
            }
            while (!s1.empty())
            {
                TreeNode *top = s1.top();
                s1.pop();
                temp.push_back(top->val);
                if (top->left)
                {
                    s2.push(top->left);
                }
                if (top->right)
                {
                    s2.push(top->right);
                }
            }

            if (!temp.empty())
            {
                result.push_back(temp);
            }
        }

        return result;
    }
};