#include <string>
#include <vector>
#include<algorithm>
using std::string, std::vector;

class Solution
{
public:
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        vector<int> dp(n, 1);

        vector<int> parent(n, -1);
        int longestSubsequence = 1;
        int longestSubsequenceIndex = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i - 1; ++j)
            {
                if (groups[i] != groups[j] &&
                    words[i].length() == words[j].length() &&
                    checkHamming(words[i], words[j]))
                {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                        if(longestSubsequence < dp[i]) {
                            longestSubsequence = dp[i];
                            longestSubsequenceIndex = i;
                        }
                    }
                }
            }
        }

        vector<string> result;
        while(longestSubsequenceIndex != -1) {
            result.push_back(words[longestSubsequenceIndex]);
            longestSubsequenceIndex = parent[longestSubsequenceIndex];
        }
        std::reverse(result.begin(), result.end());

        return result;
    }

private:
    bool checkHamming(string s1, string s2)
    {
        int hd = 0;
        for(int i = 0; i < s1.length(); ++i) {
            if(s1[i] != s2[i]) ++hd;
        }
        return hd == 1;
    }
};