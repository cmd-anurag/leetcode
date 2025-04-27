#include <vector>
using std::vector;

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int start = 0;
        int end = 2;
        int n = nums.size();

        int count = 0;

        while (end < n)
        {
            if ((nums[start] + nums[end]) * 2 == nums[start + 1])
                ++count;
            start++;
            end++;
        }
        return count;
    }
};