#include<vector>
using std::vector;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for(int i = 1; i < n; ++i) {
            int bit = nums[i];
            prefix[i] = (2 * prefix[i-1] + bit) % 5;
        }
        vector<bool> result(n);

        for(int i = 0; i < n; ++i) {
            result[i] = prefix[i] % 5 == 0;
        }
        return result;
    }
};