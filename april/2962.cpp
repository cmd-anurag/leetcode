#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {

        int maxElement = *max_element(nums.begin(), nums.end());
        long long answer = 0, start = 0;
        int count = 0;

        for (int end = 0; end < nums.size(); end++)
        {
            if (nums[end] == maxElement)
            {
                count++;
            }
            while (count == k)
            {
                if (nums[start] == maxElement)
                {
                    count--;
                }
                start++;
            }
            answer += start;
        }
        return answer;
    }
};