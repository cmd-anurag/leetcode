#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int n = tops.size();

        int candidate1 = tops[0];
        int candidate2 = bottoms[0];

        vector<int> temp(4);

        // try to make each element in tops = candidate1;
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (tops[i] == candidate1)
                continue;

            if (bottoms[i] == candidate1)
            {
                ++result;
            }
            else
            {
                result = -1;
                break;
            }
        }
        temp[0] = result;

        result = 0;
        // try to make each element in tops = candidate2;
        for (int i = 0; i < n; ++i)
        {
            if (tops[i] == candidate2)
            {
                continue;
            }
            if (bottoms[i] == candidate2)
            {
                ++result;
            }
            else
            {
                result = -1;
                break;
            }
        }
        temp[1] = result;

        // try to make each element in bottoms = candidate1;
        result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (bottoms[i] == candidate1)
                continue;

            if (tops[i] == candidate1)
            {
                ++result;
            }
            else
            {
                result = -1;
                break;
            }
        }
        temp[2] = result;

        // try to make each element in bottoms = candidate2;
        result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (bottoms[i] == candidate2)
                continue;

            if (tops[i] == candidate2)
            {
                ++result;
            }
            else
            {
                result = -1;
                break;
            }
        }
        temp[3] = result;

        sort(temp.begin(), temp.end());

        for (int x : temp)
        {
            if (x != -1)
                return x;
        }
        return -1;
    }
    // yeah there probably was a better way to do this
};