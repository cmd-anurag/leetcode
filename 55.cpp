#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int end = n-1;

        for(int i = n-1; i >= 0; --i) {
            if(nums[i] + i >= end) {
                end = i;
            }
        }
        return end == 0;
    }
};

int main() {
    
}