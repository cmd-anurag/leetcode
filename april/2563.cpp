#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    int bs(vector<int> &nums, int l, int r, int target)
    {

        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] >= target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return r;
    }

    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long result = 0;
        for (int i = 0; i < n; ++i)
        {
            int low = lower - nums[i];
            int high = upper - nums[i];

            result += bs(nums, i + 1, n - 1, high + 1) - bs(nums, i + 1, n - 1, low);
        }
        return result;
    }
};