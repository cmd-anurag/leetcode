#include <unordered_map>
#include <vector>
using std::unordered_map, std::vector;

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        long long int count = 0, prefix = 0;
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        for (int num : nums)
        {
            prefix = (prefix + (num % modulo == k)) % modulo;
            int target = (prefix - k + modulo) % modulo;
            count += prefixCount[target];
            prefixCount[prefix]++;
        }

        return count;
    }
};