#include<vector>
using std::vector;


class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int left =0;
        int right = nums.size() - 1;

        while(left < right) {
            bool leftIsPrime = false;
            bool rightIsPrime = false;

            if(isPrime(nums[left])) leftIsPrime = true;
            if(isPrime(nums[right])) rightIsPrime = true;

            if(leftIsPrime && rightIsPrime) {
                return right - left;
            }

            if(!leftIsPrime) ++left;
            if(!rightIsPrime) --right;
        }

        return 0;
    }
private:
    bool isPrime(int n) {
        // code here
        if(n <= 1) return false;
        if(n <= 3) return true;
        
        if(n % 2 == 0 || n  % 3 == 0) {
            return false;
        }
        
        for(int i = 5; i*i <= n; i += 6) {
            if(n % i == 0 || n % (i+2) == 0) {
                return false;
            }
        }
        
        return true;
    }
};