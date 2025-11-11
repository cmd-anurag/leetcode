#include<vector>
#include<string>
using std::string, std::max;
using std::vector, std::pair;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();

        vector<pair<int, int>> c(len);

        for(int i = 0; i < len; ++i) {
            int zero = 0;
            int one = 0;
            for(char ch : strs[i]) {
                if(ch == '0') {
                    ++zero;
                } else {
                    ++one;
                }
            }
            c[i] = {zero, one};
        }
        vector<vector<vector<int>>> memo(len, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        int result = solve(c, m, n, 0, memo);
        return result;
    }
private:
    int solve(vector<pair<int, int>>& c, int m, int n, int i, vector<vector<vector<int>>>& memo) {
        if(i >= c.size() || (m == 0 && n == 0)) {
            return 0;
        }

        if(memo[i][m][n] != -1) return memo[i][m][n];

        int take = 0;
        int zero = c[i].first;
        int one = c[i].second;

        if(zero <= m && one <= n) {
            take = 1 + solve(c, m - zero, n - one, i+1, memo);
        }
        int leave = solve(c, m, n, i + 1, memo);

        int ans = max(take, leave);
        memo[i][m][n] = ans;
        return ans;
    }
};