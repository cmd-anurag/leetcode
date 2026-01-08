#include<climits>
#include<vector>
using std::vector;
using std::max;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));

        vector<vector<int>> dp(n+1, vector<int>(m+1));

        for(int i = 0; i < n; ++i) {
            dp[i][m] = INT_MIN;
        }
        for(int j = 0; j < m; ++j) {
            dp[n][j] = INT_MIN;
        }
        
        for(int i = n-1; i>=0; --i) {
            for(int j = m-1; j >= 0; --j) {
                int p1 = nums1[i] * nums2[j];
                int future = dp[i+1][j+1];
                int p2 = INT_MIN;

                if(future != INT_MIN) {
                    p2 = nums1[i] * nums2[j] + future;
                }

                int p3 = dp[i+1][j];
                int p4 = dp[i][j+1];

                int result = max(p1, p2);
                result = max(result, p3);
                result = max(result, p4);
                dp[i][j] = result;
            }
        }
        // return solve(nums1, nums2, 0, 0, memo);
        return dp[0][0];
    }

    int solve(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &memo) {
        if(i >= nums1.size() || j >= nums2.size()) return INT_MIN;

        if(memo[i][j] != -1) return memo[i][j];

        // take both in the subsequence
        // here i have two choices 
        // 1-> take this pair and stop (this gives me subsequence of length 1)
        // 2 -> take this pair and continue

        // int p1 = nums1[i] * nums2[j];
        // int p2 = nums1[i] * nums2[j] + solve(nums1, nums2, i+1, j+1); -> causes overflow when solve returns INT_MIN so handle it seperately
        

        int p1 = nums1[i] * nums2[j];
        int future = solve(nums1, nums2, i+1, j+1, memo);
        int p2 = INT_MIN;

        if(future != INT_MIN) {
            p2 = nums1[i] * nums2[j] + future;
        }


        // skip one from either
        int p3 = solve(nums1, nums2, i+1, j, memo);
        int p4 = solve(nums1, nums2, i, j+1, memo);

        int result = max(p1, p2);
        result = max(result, p3);
        result = max(result, p4);
        memo[i][j] = result;
        return result;
    } 

    
};