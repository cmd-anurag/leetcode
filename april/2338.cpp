#include <vector>
using std::min;
using std::vector;

class Solution
{
public:
    const int MOD = 1000000007;
    int idealArrays(int n, int maxValue)
    {
        int m = maxValue;
        vector<vector<int>> divs(m + 1);
        for (int i = 1; i <= m / 2; i++)
            for (int j = 2 * i; j <= m; j += i)
                divs[j].push_back(i);
        int maxL = 0;
        while ((1 << maxL) <= m)
            maxL++;
        maxL = min(maxL, n);
        vector<vector<int>> dp(maxL + 1, vector<int>(m + 1));
        for (int v = 1; v <= m; v++)
            dp[1][v] = 1;
        for (int len = 2; len <= maxL; len++)
            for (int v = 1; v <= m; v++)
            {
                long long s = 0;
                for (int u : divs[v])
                    s += dp[len - 1][u];
                dp[len][v] = s % MOD;
            }
        vector<long long> fact(n), invfact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++)
            fact[i] = fact[i - 1] * i % MOD;
        auto modpow = [&](long long a, long long e)
        {
            long long r = 1;
            while (e)
            {
                if (e & 1)
                    r = r * a % MOD;
                a = a * a % MOD;
                e >>= 1;
            }
            return r;
        };
        invfact[n - 1] = modpow(fact[n - 1], MOD - 2);
        for (int i = n - 1; i > 0; i--)
            invfact[i - 1] = invfact[i] * i % MOD;
        auto C = [&](int N, int K)
        {
            if (K < 0 || K > N)
                return 0LL;
            return fact[N] * invfact[K] % MOD * invfact[N - K] % MOD;
        };
        long long ans = 0;
        for (int len = 1; len <= maxL; len++)
        {
            long long sumv = 0;
            for (int v = 1; v <= m; v++)
                sumv = (sumv + dp[len][v]) % MOD;
            ans = (ans + sumv * C(n - 1, len - 1)) % MOD;
        }
        return ans;
    }
};