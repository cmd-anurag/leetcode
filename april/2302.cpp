#include<vector>
using std::vector;
using ll = long long;

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            int n = nums.size();

            ll count = 0;
            int i = 0;
            int j = 0;

            ll sum = 0;
            for(int j = 0; j < n; ++j) {
                sum += nums[j];

                while(i <= j && sum * (j-i+1) >= k) {
                    sum -= nums[i];
                    ++i;
                }
                
                count += (j-i) + 1;
            }

            return count;
            
        }
    };