// binary exponentiation 

class Solution
{
public:
    const long long int MOD = 1e9 + 7;

    long long int power(long long int x, long long int n)
    {
        if (n == 0)
            return 1;

        x = x % MOD;
        int result = 1;
        while (n > 1)
        {
            if (n & 1)
            {
                result = (result * x) % MOD;
            }

            n /= 2;
            x = (x * x) % MOD;
        }

        return (result * x) % MOD;
    }

    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};
