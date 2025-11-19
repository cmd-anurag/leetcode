#include<vector>
using std::vector;
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        while(true) {
            int index = findOriginal(nums, original);
            if(index == -1) return original;
            original *= 2;
        }
    }
private:
    int findOriginal(vector<int> &nums, int original) {
        for(int i = 0; i < nums.size(); ++i) {
            if(original == nums[i]) {
                return i;
            }
        }
        return -1;
    }
};