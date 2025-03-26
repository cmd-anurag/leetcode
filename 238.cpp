#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        vector<int> leftProduct(n);
        vector<int> rightProduct(n);

        int product = 1;

        for(int i = 0; i < n; ++i) {
            leftProduct[i] = product;
            product *= nums[i];
        }

        product = 1;

        for(int i = n-1; i >= 0; --i) {
            rightProduct[i] = product;
            product *= nums[i];
        }

        for(int i = 0; i < n; ++i) {
            result[i] = leftProduct[i] * rightProduct[i];
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4};
    s.productExceptSelf(nums);
}