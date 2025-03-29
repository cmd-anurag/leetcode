#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int maximumScore(vector<int> &nums, int k)
    {
        long long int score = 1;
        int n = nums.size();

        vector<int> primeScores(n);
        for (int i = 0; i < n; ++i)
        {
            primeScores[i] = getPrimeScore(nums[i]);
        }

        vector<int> nextDom(n, n);
        vector<int> prevDom(n, -1);

        stack<int> st;

        for (int i = 0; i < n; ++i)
        {
            int element = nums[i];
            int PrimeScore = primeScores[i];

            while (!st.empty() && PrimeScore > primeScores[st.top()])
            {
                int top = st.top();
                st.pop();
                nextDom[top] = i;
            }

            if (!st.empty())
            {
                prevDom[i] = st.top();
            }

            st.push(i);
        }

        vector<long long int> subCount(n);
        for (int i = 0; i < n; ++i)
        {
            subCount[i] = (long long int)(nextDom[i] - i) * (i - prevDom[i]);
        }

        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            q.push({nums[i], i});
        }
        int mod = 1e9 + 7;
        while (k > 0)
        {
            auto [value, i] = q.top();
            q.pop();

            long long int operations = min((long long int)k, subCount[i]);
            score = (score * power(value, operations)) % mod;
            k -= operations;
        }

        return score;
    }

private:
    int getPrimeScore(int n)
    {
        int count = 0;

        if (n % 2 == 0)
        { // 2 is a factor;
            ++count;
            while (n % 2 == 0)
                n /= 2;
        }

        for (int i = 3; i * i <= n; ++i)
        { // odd factors
            if (n % i == 0)
            {
                ++count;
                while (n % i == 0)
                    n /= i;
            }
        }

        if (n > 1)
            ++count;

        return count;
    }

    long long int power(long long int b, long long int e)
    {
        long long result = 1;
        while (e > 0)
        {
            if (e % 2 == 1)
            {
                result = ((result * b) % mod);
            }

            b = (b * b) % mod;
            e /= 2;
        }
        return result;
    }
};