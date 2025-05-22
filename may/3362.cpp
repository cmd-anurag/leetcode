#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        priority_queue<int> heap;
        vector<int> arr(nums.size() + 1, 0);
        int ops = 0;

        for (int i = 0, j = 0; i < nums.size(); ++i)
        {
            ops += arr[i];
            while (j < queries.size() && queries[j][0] == i)
            {
                heap.push(queries[j][1]);
                ++j;
            }
            while (ops < nums[i] && !heap.empty() && heap.top() >= i)
            {
                ops += 1;
                arr[heap.top() + 1] -= 1;
                heap.pop();
            }
            if (ops < nums[i])
            {
                return -1;
            }
        }

        return heap.size();
    }
    // damn..
};