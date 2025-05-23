#include<vector>
#include <climits>
#include<cmath>

using std::vector;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long result = 0;
        int count = 0;
        int minLoss = INT_MAX;

        for(int value : nums) {
            int updatedValue = value ^ k;

            if(updatedValue > value) {
                ++count;
                result += updatedValue;
            } else {
                result += value;
            }

            minLoss = std::min(std::abs(value - updatedValue), minLoss);

        }
        return count & 1? result - minLoss : result;
    }
};