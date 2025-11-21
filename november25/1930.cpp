#include<unordered_set>
#include<vector>
#include<string>
using std::string;
using std::unordered_set, std::vector;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> right(26, 0);

        for(char c : s) {
            right[c - 'a']++;
        }

        unordered_set<char> left;
        unordered_set<string> pals;

        int count = 0;

        for(char c : s) {

            int freq = right[c - 'a'];
            if(freq != 0) {
                freq--;
                right[c - 'a'] = freq;
            }

            for(int element : left) {
                string pal;
                pal.push_back(element);
                pal.push_back(c);

                if(right[element - 'a'] > 0 && pals.find(pal) == pals.end()) {
                    ++count;
                    pals.insert(pal);
                }
            }
            left.insert(c);
        }

        return count;
    }
};