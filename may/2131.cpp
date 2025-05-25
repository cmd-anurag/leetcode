#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        for (const string& word : words) {
            count[word]++;
        }

        int length = 0;
        bool hasCentral = false;

        for (auto& [word, freq] : count) {
            string rev = string{word.rbegin(), word.rend()};
            if (word == rev) {
                int pairs = freq / 2;
                length += pairs * 4;
                count[word] -= pairs * 2;
                if (count[word] > 0) hasCentral = true;
            } else if (count.find(rev) != count.end()) {
                int pairs = min(freq, count[rev]);
                length += pairs * 4;
                count[word] -= pairs;
                count[rev] -= pairs;
            }
        }

        if (hasCentral) length += 2;
        return length;
    }
};
