#include <queue>
#include <climits>
using std::queue;
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
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        int level = 1;
        int maxSum = INT_MIN;
        int maxLevel = 1;

        while (!q.empty())
        {
            int sum = 0;
            int size = q.size();

            for (int i = 0; i < size; ++i)
            {
                auto front = q.front();
                q.pop();
                sum += front->val;

                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
            if (sum > maxSum)
            {
                maxLevel = level;
                maxSum = sum;
            }
            level++;
        }
        return maxLevel;
    }
};