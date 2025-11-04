#include<unordered_map>
#include<queue>
#include<vector>
using std::vector, std::pair, std::priority_queue, std::unordered_map;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int i = 0;
        int j = k - 1;
        vector<int> result;
        while(j < nums.size())
        {
            int sum = xSum(nums, i, j, x);
            result.push_back(sum);
            j++;
            i++;
        }
        return result;
    }
private:
    int xSum(vector<int>& nums, int start, int end, int x) {
        unordered_map<int, int> map;
        for(int i = start; i <= end; ++i) {
            int element = nums[i];
            map[element]++;
        }

        priority_queue<pair<int, int>> maxHeap;

        for(auto pair : map) {
            maxHeap.push({pair.second, pair.first});
        }

        int sum = 0;
        for(int i = 0; i < x; ++i) {
            if(maxHeap.empty()) break;
            auto top = maxHeap.top();

            sum += top.first * top.second;
            maxHeap.pop();
        }
        return sum;
    }
};
// hardest part about the problem was having to read it