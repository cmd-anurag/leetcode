#include <vector>
using std::vector;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();

        int i = 0;
        int j = 0;

        long long product = 1;
        int count = 0;

        for(int j = 0; j < n; ++j) {
            product *= nums[j];

            while(i <= j && product >= k) {

                product /= nums[i];
                i++;
                
            }

            count += j-i+1;
        }

        return count;

    }
};