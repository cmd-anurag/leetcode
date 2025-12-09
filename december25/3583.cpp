#include<vector>
#include<unordered_map>

using std::vector, std::unordered_map;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int M = 1e9 + 7;

        unordered_map<int, int> left;
        unordered_map<int, int> right;
        int n = nums.size();

        left[nums[0]]++;
        for(int i = 1; i < n; ++i) {
            right[nums[i]]++;
        }

        long long count = 0;
        for(int i = 1; i < n; ++i) {

            int middle = nums[i];
            
            right[middle]--;
            if(right[middle] <= 0) {
                right.erase(middle);
            }

            int countOnLeft = left[middle * 2] % M;
            int countOnRight = right[middle * 2] % M;

            if(countOnLeft && countOnRight) {
                count = (count + 1LL * countOnLeft * countOnRight) % M;
            }

            left[middle]++;

        }
        return count;
    }
};