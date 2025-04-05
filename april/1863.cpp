#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    // this is the classic subset generation 
        int ans = 0;
        void recur(vector<int> nums, int sum, int i) {
            if(i == nums.size()) {
                ans += sum;
                return;
            }
            recur(nums, sum ^ nums[i], i+1);
            recur(nums, sum, i+1);
        }
    
        int subsetXORSum(vector<int>& nums) {
            // recur(nums, 0, 0);

            // the bitwise solution
            int result = 0;
            int n = nums.size();

            for(int i : nums) {
                result = result | i;
            }

            return result << n-1;
            
        }
    };