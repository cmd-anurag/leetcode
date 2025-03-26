#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSquareStreak(std::vector<int>& arr) {
        int maxStreak = 0;
        std::unordered_set<int> uniqueElements(arr.begin(), arr.end());

        for (int initial : arr) {
            int currentStreak = 0;
            long long currentValue = initial;

            while (uniqueElements.find((int)currentValue) != uniqueElements.end()) {
                currentStreak++;
                if (currentValue * currentValue > 1e5) break;
                currentValue *= currentValue;
            }

            maxStreak = std::max(maxStreak, currentStreak);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};
