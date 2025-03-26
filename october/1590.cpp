#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

int minSubarray(vector<int>& nums, int p) {
        int Sum = 0;
        for(int i : nums) {
            Sum = (Sum + i) % p;
        }
        int target = Sum%p;
        if(target == 0) return 0;
        unordered_map<int, int> prefixSumModp;
        prefixSumModp[0] = -1;
        int curSum = 0;
        int result = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            curSum = (curSum + nums[i]) % p;
            int req = (curSum - target + p) % p;
            if(prefixSumModp.find(req) != prefixSumModp.end()) {
                result = min(result, i - prefixSumModp[req]);
            }
            prefixSumModp[curSum] = i;
        }
        if(result == nums.size()) {
            return -1;
        }
        else {
            return result;
        }
    }

int main() {
    
}