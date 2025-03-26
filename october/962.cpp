#include<iostream>
#include<vector>

using namespace std;

int maxWidthRamp(vector<int>& nums) {

    int n = nums.size();
    vector<int> maxToRight(n);
    int maxSoFar = nums[n-1];
    maxToRight[n-1] = maxSoFar;

    for(int i = n-2; i>=0; --i) {
        if(nums.at(i) > maxSoFar) {
            maxSoFar = nums.at(i);
        }
        maxToRight[i] = maxSoFar;
    }

    int left = 0;
    int right = 1;

    int result = 0;

    while(left < n && right < n) {
        if(nums.at(left) <= nums.at(right) || maxToRight[right] > nums.at(left)) {
            result = right-left > result? right-left : result;
            ++right;
        }
        else {
            left++;
            right++;
        }
    }
   
   return result;
}

int main()
{
    vector<int> nums = {9,8,1,0,1,9,4,0,4,1};
    cout << maxWidthRamp(nums);
    return 0;
}