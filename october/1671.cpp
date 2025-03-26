#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums.at(j) < nums.at(i)) {
                    lis.at(i) = max(lis.at(i), 1+lis.at(j));
                }
            }
        }

        for(int i = n-1; i >= 0; --i) {
            for(int j = i+1; j < n; ++j) {
                if(nums.at(j) < nums.at(i)) {
                    lds.at(i) = max(lds.at(i), 1+lds.at(j));
                }
            }
        }

        int output = n;

        for(int i = 1; i < n-1; ++i) {
            if(min(lis[i], lds[i]) > 1) {
                output = min(output, n - lis[i] - lds[i] + 1);
            }
        }
        return output;
    }
};


int main()
{
    
    return 0;
}