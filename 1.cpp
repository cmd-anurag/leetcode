#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result(2, -1);

        unordered_map<int, int> hash;

        for(int i = 0; i < n; ++i) {
            int expected = target - nums[i];
            if(hash.find(expected) != hash.end()) {
                result[0] = i;
                result[1] = hash[expected];
                return result;
            }
            else {
                hash[nums[i]] = i;
            }
        }
        return result;
    }
};

int main() {

}