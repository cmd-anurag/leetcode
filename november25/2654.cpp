#include<vector>
#include<climits>
using std::vector;
using std::min;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int currentGCD = nums[0];
        int result = INT_MAX;

        int count = 0;
        for(auto x : nums) {
            if(x == 1) ++count;
        }

        if(count == n) return 0;
        if(count != 0) return n - count;

        for(int i = 0; i < n - 1; ++i) {
            currentGCD = nums[i];

            for(int j = i+1; j < n; ++j) {

                currentGCD = gcd(currentGCD, nums[j]);

                if(currentGCD == 1) {
                    
                    result = min(result, (j - i) + (n - 1));
                    // cout << result << " " << i << " " << j << '\n';
                    break;
                }
            }
        }
        return result == INT_MAX? -1 : result;
    }
private:
    int gcd(int a, int b) {
        if(b == 0) return a;

        return gcd(b, a % b);
    }
};