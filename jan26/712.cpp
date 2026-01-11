#include<vector>
#include<string>
using std::vector, std::string, std::min;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // return solve(s1, s2, 0, 0);
        // nice it works
        // top down memoization
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));

        // return solve(s1, s2, 0, 0, memo);

        // tabulate
        vector<vector<int>> dp(n+1, vector<int>(m+1));

        // base cases
        for(int j = 0; j <= m; ++j) {
            dp[n][j] = getSum(s2, j);
        }
        for(int i = 0; i <= n; ++i) {
            dp[i][m] = getSum(s1, i);
        }

        for(int i = n-1; i >= 0; --i) {
            for(int j = m-1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    int p1 = s1[i] + dp[i+1][j];
                    int p2 = s2[j] + dp[i][j+1];

                    dp[i][j] = min(p1, p2);
                }
            }
        }

        return dp[0][0];
    }

    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &memo) {
        
        // base case ?
        if(i >= s1.size() && j >= s2.size()) return 0;

        if(i == s1.size()) {
            return getSum(s2, j);
        }
        if(j == s2.size()) {
            return getSum(s1, i);
        }

        if(memo[i][j] != -1) return memo[i][j];

        if(s1[i] == s2[j]) {
            return memo[i][j] = solve(s1, s2, i+1, j+1, memo);
        } else {
            int p1 = s1[i] + solve(s1, s2, i+1, j, memo);
            int p2 = s2[j] + solve(s1, s2, i, j+1, memo);

            return memo[i][j] = min(p1, p2);
        }
    }

    int getSum(string &s, int start) {
        int sum = 0;
        for(int i= start; i < s.size(); ++i) {
            sum += s[i];
        }

        return sum;
    }
};