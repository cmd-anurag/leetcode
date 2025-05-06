#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        // the easy answer is literally given in the question lol

        // vector<int> result(nums.size());

        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     result[i] = nums[nums[i]];
        // }

        // return result;

        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            int oldVal = nums[i];
            int newVal = nums[nums[i]] % 1000;

            int combined = oldVal + 1000 * newVal;

            nums[i] = combined;
        }

        for(int i = 0; i < n; ++i) {
            nums[i] = nums[i] / 1000;
        }

        return nums;

    }
};

