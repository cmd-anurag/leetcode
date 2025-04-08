#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {

        int n = nums.size();

        unordered_set<int> set;

        int ops = 0;

        int j = 0;
        for (int i = 0; i < n;)
        {
            if (set.find(nums[i]) == set.end())
            {
                set.insert(nums[i]);
                ++i;
            }
            else
            {
                j += 3;
                ++ops;
                if (j >= n)
                    return ops;
                set.clear();
                set.insert(nums[j]);
                i = j + 1;
            }
        }

        return ops;
    }
};