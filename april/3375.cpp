#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        unordered_set<int> set;
        for (int i : nums)
        {
            if (i > k)
            {
                set.insert(i);
            }
            else if (i < k)
            {
                return -1;
            }
        }
        return set.size();
    }
};