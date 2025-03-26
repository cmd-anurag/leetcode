#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        sort(robots.begin(), robots.end());
    vector<pair<int, int>> factoryList;

    for (const auto& f : factories) {
        factoryList.emplace_back(f[0], f[1]);
    }

    sort(factoryList.begin(), factoryList.end());
    int n = robots.size(), m = factoryList.size();
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LLONG_MAX));
    dp[0][0] = 0;

    for (int j = 1; j <= m; ++j) {
        dp[j][0] = 0;
        for (int i = 1; i <= n; ++i) {
            long long distance = 0;
            for (int k = 0; k <= min(factoryList[j - 1].second, i); ++k) {
                if (k > 0) {
                    distance += abs(robots[i - k] - factoryList[j - 1].first);
                }
                if (dp[j - 1][i - k] != LLONG_MAX) {
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - k] + distance);
                }
            }
        }
    }

    return dp[m][n];
    }
};

int main() {
    
}