#include <string>
using std::string, std::to_string;

class Solution
{
public:
    // i aged significantly understanding this problem lol

    string helper(string t)
    {
        int n = t.length();

        string output = "";

        for (int i = 0; i < n; i++)
        {
            char letter = t[i];
            int freq = 0;

            int j = i;
            for (; j < n && t[j] == letter; ++j)
            {
                ++freq;
            }
            i = j - 1;

            output += to_string(freq) + letter;
        }

        return output;
    }

    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        return helper(countAndSay(n - 1));
    }
};