#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; ++i) {
            string s = to_string(i);
            if(s.size() & 1) {
                continue;
            }
            int sum1 = 0;
            int sum2 = 0;

            int m = s.size()/2;

            for(int i = 0; i < m; ++i) {
                sum1 += s[i] - '0';
            }
            for(int i = m; i < s.size(); ++i) {
                sum2 += s[i] - '0';
            }

            if(sum1 == sum2) count++;
        }
        return count;
    }
};