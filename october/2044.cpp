#include<iostream>
#include<vector>

using namespace std;

int maxOR = 0;
int result = 0;

void recurse(int i, int currentOR, vector<int>& nums, int n) {
    if(i == n) {
        if(currentOR == maxOR) ++result;
        return;
    }
    recurse(i+1, currentOR, nums, n);
    recurse(i+1, currentOR | nums[i], nums, n);
}

int countMaxOrSubsets(vector<int>& nums) {
    
    for(int i : nums) {
        maxOR |= i;
    }

    recurse(0, 0, nums, nums.size());
    return result;
}


int main()
{
    
    return 0;
}