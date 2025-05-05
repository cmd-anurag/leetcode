#include <unordered_map>
#include <vector>
using std::unordered_map, std::vector;


class Solution
{
public:
    const int MOD = 1e9 + 7;

    int numTilings(int n)
    {

        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (i < 3)
            {
                dp[i] = i;
            }
            else
            {
                dp[i] = (2 * (dp[i - 1] % MOD) % MOD + dp[i - 3] % MOD) % MOD;
            }
        }

        // return solve(n);
        return dp[n];
    }

private:
    unordered_map<int, int> memo;

    int solve(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        if (memo.find(n) != memo.end())
        {
            return memo[n];
        }
        else
        {
            int answer = solve(n - 1) % MOD;
            answer = (answer * 2) % MOD;
            answer = (answer + solve(n - 3) % MOD) % MOD;
            memo[n] = answer;
            return answer;
        }
    }
};