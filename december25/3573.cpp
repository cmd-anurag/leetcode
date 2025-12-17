#include<vector>
#include<climits>
using std::vector;
using std::max;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // vector<vector<vector<long long>>> memo(k+1, vector<vector<long
        // long>>(n, vector<long long>(3, -1))); return solve(prices, k, 0, 0,
        // memo);

        vector<vector<vector<long long>>> dp(
            k + 1, vector<vector<long long>>(n + 1, vector<long long>(3, 0)));

        for (int temp = 0; temp <= k; ++temp) {
            dp[temp][n][1] = LLONG_MIN / 2;
            dp[temp][n][2] = LLONG_MIN / 2;
        }
        for (int temp = 0; temp <= n; ++temp) {
            dp[0][temp][1] = LLONG_MIN / 2;
            dp[0][temp][2] = LLONG_MIN / 2;
        }

        for (int t = 1; t <= k; ++t) {
            for (int i = n - 1; i >= 0; --i) {
                for (int status = 0; status <= 2; ++status) {
                    if (status == 0) {
                        long long b = -prices[i] + dp[t][i + 1][1];
                        long long s = prices[i] + dp[t][i + 1][2];
                        long long skip = dp[t][i + 1][0];
                        dp[t][i][status] = max(skip, max(b, s));
                    } else if (status == 1) {
                        long long s = prices[i] + dp[t - 1][i + 1][0];
                        long long skip = dp[t][i + 1][1];
                        dp[t][i][status] = max(s, skip);
                    } else {
                        long long b = -prices[i] + dp[t - 1][i + 1][0];
                        long long skip = dp[t][i + 1][2];
                        dp[t][i][status] = max(b, skip);
                    }
                }
            }
        }

        return dp[k][0][0];
    }

    // status = 0 -> none
    // status = 1 -> buy done
    // status = 2 -> short sell done
    long long solve(vector<int>& prices, int k, int i, int status,
                    vector<vector<vector<long long>>>& memo) {

        if (i >= prices.size()) {
            if (status == 0)
                return 0;
            return LLONG_MIN / 2;
        }

        if (k == 0) {
            if (status == 0)
                return 0;
            return LLONG_MIN / 2;
        }

        if (memo[k][i][status] != -1)
            return memo[k][i][status];

        if (status == 0) {
            // buy the stock
            long long b = -prices[i] + solve(prices, k, i + 1, 1, memo);
            // short sell the stock
            long long s = prices[i] + solve(prices, k, i + 1, 2, memo);

            // skip
            long long skip = solve(prices, k, i + 1, 0, memo);
            return memo[k][i][status] = max(skip, max(b, s));

        } else if (status == 1) {
            // sell the stock
            long long s = prices[i] + solve(prices, k - 1, i + 1, 0, memo);
            // skip
            long long skip = solve(prices, k, i + 1, 1, memo);
            return memo[k][i][status] = max(s, skip);
        } else {
            // buy the stock
            long long b = -prices[i] + solve(prices, k - 1, i + 1, 0, memo);
            // skip
            long long skip = solve(prices, k, i + 1, 2, memo);
            return memo[k][i][status] = max(b, skip);
        }
    }
};