#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {

            
            int n = nums.size();
            vector<int> left(n);
            vector<int> right(n);
    
            int maxVal = 0;
            for(int i = 0; i < n; ++i) {
                maxVal = max(nums[i], maxVal);
                left[i] = maxVal;
            }
            maxVal = 0;
            for(int i = n-1; i >= 0; --i) {
                maxVal = max(nums[i], maxVal);
                right[i] = maxVal;
            }
            long long result = 0;
            
            for(int j = 1; j < n-1; ++j) {
                int i = left[j-1];
                int k = right[j+1];
                long long points = (long long) (i - nums[j]) * k;
                result = max(points, result);
            }
            
            // this was an elegant solution
            return result;
    
        }
    };