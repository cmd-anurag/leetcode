#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;

        unordered_map<int, int> map;
        int n = nums2.size();

        for (int i = n - 1; i >= 0; --i)
        {
            int element = nums2[i];

            while (!st.empty() && element >= st.top())
            {
                st.pop();
            }

            if (!st.empty())
            {
                map[element] = st.top();
            }
            else
            {
                map[element] = -1;
            }

            st.push(element);
        }
        vector<int> result(nums1.size());

        for (int i = 0; i < nums1.size(); ++i)
        {
            int element = nums1[i];
            result[i] = map[element];
        }

        return result;
    }
};