#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(int i : nums) {
            maxHeap.push(i);
        }

        for(int i = 0; i < k-1; ++i) {
            maxHeap.pop();
        }

        return maxHeap.top();
    }
};

int main() {

}