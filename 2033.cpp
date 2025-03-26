#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {

        vector<int> flat;
        int mod = grid[0][0] % x;
        
        for (auto i : grid)
        {
            for (auto j : i)
            {
                if (j % x != mod) // remainder mismatch
                {
                    return -1;
                }
                flat.push_back(j);
            }
        }

        
        sort(flat.begin(), flat.end());
        int median = flat[flat.size() / 2];

        int ops = 0;
        for (int i : flat)
        {
            // how far is the number from median
            ops += abs(median - i) / x;
        }

        return ops;
    }
};