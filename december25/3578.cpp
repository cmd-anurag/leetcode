#include<deque>
#include<vector>
using std::deque;
using std::vector;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> dpSum(n + 2, 0);
        dpSum[1] = 1;
        deque<int> maxD, minD;
        
        int L = 0;         
        for (int i = 0; i < n; ++i) {
            
            while (!maxD.empty() && nums[maxD.back()] <= nums[i]) maxD.pop_back();
            maxD.push_back(i);

            while (!minD.empty() && nums[minD.back()] >= nums[i]) minD.pop_back();
            minD.push_back(i);

            while (nums[maxD.front()] - nums[minD.front()] > k) {
                L++;
        
                if (maxD.front() < L) maxD.pop_front();
                if (minD.front() < L) minD.pop_front();
            }
            
            int currentWays = (dpSum[i + 1] - dpSum[L] + MOD) % MOD;
            dp[i + 1] = currentWays;
            dpSum[i + 2] = (dpSum[i + 1] + currentWays) % MOD;
        }

        return dp[n];
    }
};