#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {

        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }

        if (sum & 1)
            return false;
        int target = sum / 2;

        unordered_set<int> set;
        set.insert(0);

        int n = nums.size();
        for (int i = n - 1; i >= 0; --i)
        {
            vector<int> temp;

            for (auto element : set)
            {
                int result = element + nums[i];
                if (result == target)
                    return true;
                temp.push_back(result);
            }

            for (int x : temp)
            {
                set.insert(x);
            }
            temp.clear();
        }

        return false;
    }
};