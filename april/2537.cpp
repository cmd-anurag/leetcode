#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int n = nums.size();
    
            if (k == 0)
                return (long long)n * (n + 1) / 2;
    
            long long count = 0, pairs = 0;
            int left = 0;
    
            unordered_map<int, long long> freq;
    
            for (int right = 0; right < n; right++) {
                pairs += freq[nums[right]];
                freq[nums[right]]++;
    
                while (pairs >= k && left <= right) {
                    count += (n - right);
                    freq[nums[left]]--;
                    pairs -= freq[nums[left]];
                    left++;
                }
                
            }
            return count;
        }
    };