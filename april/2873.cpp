#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long int result = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    long long int points = (long long)(nums[i] - nums[j]) * nums[k];
                    result = max(points, result);
                }
            }
        }
        if (result > 0)
        {
            return result;
        }
        else
        {
            return 0;
        }
    }
};