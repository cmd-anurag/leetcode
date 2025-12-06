#include<vector>
using std::vector;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int totalSum = 0;

        for(int x : nums) {
            totalSum += x;
        }

        int partitionIndex = 0;
        int leftSum = 0;
        int rightSum = totalSum;

        while(partitionIndex < n-1) {
            leftSum += nums[partitionIndex];
            rightSum -= nums[partitionIndex];

            if(!((leftSum - rightSum) & 1)) {
                // cout << leftSum << " " << rightSum << " " << partitionIndex << '\n';
                ++count;
            }
            ++partitionIndex;
        }
        return count;
    }
};