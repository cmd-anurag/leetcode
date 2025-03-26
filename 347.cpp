#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    struct Compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };


    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int i : nums) {
            freq[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxHeap;

        for(auto i : freq) {
            maxHeap.push(make_pair(i.first, i.second));
        }

        vector<int> result;

        while(k > 0) {
            auto element = maxHeap.top();
            maxHeap.pop();
            result.push_back(element.first);
            --k;
        }

        return result;
    }
};