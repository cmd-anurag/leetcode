#include<vector>
#include<queue>
using std::vector, std::priority_queue;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long> maxHeap(happiness.begin(), happiness.end());

        long long result = 0;
        int decreases = 0;


        while(!maxHeap.empty()) {
            if(decreases == k) break;

            long long top = maxHeap.top();
            maxHeap.pop();

            if(top <= decreases) break;

            result += top - decreases;
            decreases++;
        }

        return result;

    }
};