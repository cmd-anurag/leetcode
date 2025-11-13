#include <string>
using std::string;

class Solution
{
public:
    int maxOperations(string s)
    {

        int count = 0;

        int result = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i)
        {

            if (s[i] == '1')
                ++count;
            else
            {
                if (i > 0 && s[i - 1] == '1')
                {
                    result += count;
                }
            }
        }

        return result;
    }
};