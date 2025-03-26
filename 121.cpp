#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxInFuture(n);

        int maxVal = INT_MIN;

        for(int i = n-1; i >= 0; --i) {
            maxVal = max(prices[i], maxVal);
            maxInFuture[i] = maxVal;
        }

        int profit = 0;

        for(int i = 0; i < n; ++i) {
            profit = max(profit, maxInFuture[i] - prices[i]);
        }

        return profit;
    }
};