#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp = nums;
    for(int i = 0; i < n; ++i) {
        nums[(i+k)%n] = temp[i];
    }
}

int main()
{
    
    return 0;
}