#include<unordered_set>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        unordered_set<int> set;
        for(int i : nums) {
            set.insert(i);
        }

        int length = 0;
        int maxLength = 0;

        for(int i = 0; i < n; ++i) {
            if(set.find(nums[i]-1) == set.end()) {
                length = 1;
                int num = nums[i] + 1;
                while(set.find(num) != set.end()) {
                    ++length;
                    ++num;
                }
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
};

int main() {
    Solution s;
    vector<int> nums = {100,4,200,1,3,2};
    cout << s.longestConsecutive(nums);
}