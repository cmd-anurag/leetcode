#include<vector>
using std::vector;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        
        int last = -1;

        for(int i = 0; i < n; ++i) {
            if(nums[i] == 1) {
                if(last == -1) {
                    last = i;
                    continue;
                }
                
                if(i - last - 1 < k) {
                    return false;
                }

                last = i;
            } 
        }

        return true;
    }
};