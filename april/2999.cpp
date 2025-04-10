#include <bits/stdc++.h>
using namespace std;

// i have no idea
class Solution
{
public:
    long long numberOfPowerfulInt(long long startNum, long long finishNum, int limit,
                                  string suffixStr)
    {
        string startStr = to_string(startNum - 1), finishStr = to_string(finishNum);
        return calculateCount(finishStr, suffixStr, limit) - calculateCount(startStr, suffixStr, limit);
    }

    long long calculateCount(string numStr, string suffixStr, int limit)
    {
        if (numStr.length() < suffixStr.length())
        {
            return 0;
        }
        if (numStr.length() == suffixStr.length())
        {
            return numStr >= suffixStr ? 1 : 0;
        }

        string extractedSuffix = numStr.substr(numStr.length() - suffixStr.length(), suffixStr.length());
        long long totalCount = 0;
        int prefixLen = numStr.length() - suffixStr.length();

        for (int idx = 0; idx < prefixLen; idx++)
        {
            if (limit < (numStr[idx] - '0'))
            {
                totalCount += (long)pow(limit + 1, prefixLen - idx);
                return totalCount;
            }
            totalCount += (long)(numStr[idx] - '0') * (long)pow(limit + 1, prefixLen - 1 - idx);
        }
        if (extractedSuffix >= suffixStr)
        {
            totalCount++;
        }
        return totalCount;
    }
};