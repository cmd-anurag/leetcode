#include<unordered_map>
#include<vector>
using std::vector;
using std::unordered_map;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> map;

        for(int x : nums) {
            map[x]++;
        }

        for(int x : nums) {
            if(map[x] == nums.size() / 2) return x;
        }
        return -1;
    }
};