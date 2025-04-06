#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            if(nums.empty()) return {};
    
            int n = nums.size();
    
            sort(nums.begin(), nums.end());
    
            vector<int> dp(n, 1); 
            vector<int> parent(n, -1); 
    
            int maxLength = 1;
            int maxIndex = 0;
    
            for(int i = 1;  i < n; ++i) {
                for(int j = 0; j < i; ++j) {
                   
                    if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    } 
                }
                if(dp[i] > maxLength) {
                    maxLength = dp[i];
                    maxIndex = i;
                }
            }
    
            vector<int> result;
            for(int i = maxIndex; i != -1; i = parent[i]) {
                result.push_back(nums[i]);
            }
    
            reverse(result.begin(), result.end());
    
            return result;
    
        }
    };