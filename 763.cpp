#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();
        vector<int> map(26, -1);

        for (int i = 0; i < n; ++i)
        {
            int key = (int)(s[i] - 'a');
            map[key] = i;
        }

        int size = 0;
        int lastIndex = -1;
        vector<int> result;

        for (int i = 0; i < n; ++i)
        {
            int key = (int)(s[i] - 'a');
            int currentLastIndex = map[key];
            lastIndex = max(currentLastIndex, lastIndex);
            ++size;

            if (i == lastIndex)
            {
                result.push_back(size);
                size = 0;
            }
        }

        return result;
    }
};