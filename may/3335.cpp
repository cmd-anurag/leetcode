#include <vector>
#include <string>
using std::vector, std::string;

class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        const int MOD = 1e9 + 7;
        vector<int> map(26, 0);

        for (char c : s)
        {
            map[c - 'a']++;
        }

        for (int i = 0; i < t; ++i)
        {
            vector<int> temp(26, 0);

            int z = map[25];
            temp[0] += z;
            temp[1] += z;

            for (int i = 0; i < 25; ++i)
            {
                temp[i + 1] += map[i] % MOD;
            }

            map = temp;
        }
        int total = 0;
        for (int i = 0; i < 26; ++i)
        {
            total = (total + (map[i] % MOD)) % MOD;
        }

        return total;
    }
};
