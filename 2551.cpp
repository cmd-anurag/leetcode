#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();

        vector<long long int> splits(n - 1);

        for (int i = 0; i < n - 1; ++i)
        {
            splits[i] = weights[i] + weights[i + 1];
        }

        sort(splits.begin(), splits.end());

        long long int x = 0;
        long long int y = 0;

        for (int i = 0; i < k - 1; ++i)
        {
            x += splits[i];
        }

        for (int i = 0; i < k - 1; ++i)
        {
            y += splits[splits.size() - 1 - i];
        }

        return y - x;
    }
};