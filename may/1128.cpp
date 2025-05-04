// dominoes month??

#include <vector>
using std::vector;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {

        vector<int> map(100, 0);
        int result = 0;
        for (vector<int> pair : dominoes)
        {
            if (pair[0] > pair[1])
            {
                int temp = pair[0];
                pair[0] = pair[1];
                pair[1] = temp;
            }
            int key = pair[0] * 10 + pair[1];
            map[key]++;
        }

        for (int x : map)
        {
            if (x < 2)
                continue;

            result += x * (x - 1) / 2;
        }

        return result;
    }
};