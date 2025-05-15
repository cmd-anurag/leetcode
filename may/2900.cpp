#include <vector>
#include <string>
using std::vector, std::string;

class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> answer;

        int n = groups.size();

        answer.push_back(words[0]);
        int lastUsed = groups[0];

        for (int i = 1; i < n; ++i)
        {
            string word = words[i];
            int bit = groups[i];

            if (bit != lastUsed)
            {
                lastUsed = bit;
                answer.push_back(word);
            }
        }

        return answer;
    }
};