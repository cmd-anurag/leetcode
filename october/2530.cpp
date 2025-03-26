#include<iostream>
#include<vector>
#include<math.h>
#include<queue>

using namespace std;

long long maxKelements(vector<int>& nums, int k) {
    long long score = 0;
    priority_queue<int> maxHeap;
    for(int i = 0; i < nums.size(); ++i) {
        maxHeap.push(nums.at(i));
    }
    for(int i = 0;  i < k; ++i) {
        int maxScore = maxHeap.top();
        score += maxScore;
        maxHeap.pop();
        int replace = ceil((double)maxScore/3);
        maxHeap.push(replace);
    }
    return score;
}

int main()
{
    vector<int> nums = {1,10,3,3,3};
    cout << maxKelements(nums, 3);
    return 0;
}