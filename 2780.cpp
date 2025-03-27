#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            vector<int> left(n);
            vector<int> right(n);
    
            // first count the dominant element
            unordered_map<int, int> map;
    
            for(int i : nums) {
                map[i]++;
            }
    
            int dominant = nums[0];
    
            for(auto& p : map) {
                if(p.second > map[dominant]) {
                    dominant = p.first;
                }
            }
    
            // populate the left and right arrays.
            int count = 0;
            for(int i = 0; i < n; ++i) {
                if(nums[i] == dominant) {
                    ++count;
                }
                left[i] = count;
            }
    
            count = 0;
            for(int i = n-1; i >= 0; --i) {
                if(nums[i] == dominant) {
                    ++count;
                }
                right[i] = count;
            }
    
            // for(int i : left) {
            //     cout << i << " ";
            // }
            // cout<<"\n";
            // for(int i : right) {
            //     cout << i << " ";
            // }
    
            for(int i = 0; i < n-1; ++i) {
                int p1 = i+1;
                int p2 = n-p1;
    
                if(left[i]*2 > p1 && right[i+1]*2 > p2) {
                    return i;
                }
            }
    
            return -1;
        }
    };