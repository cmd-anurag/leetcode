#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int i = digits.size() - 1;

        while (digits[i] == 9)
        {
            if (i == 0)
            {
                digits[i] = 1;
                digits.push_back(0);
                return digits;
            }
            digits[i] = 0;
            --i;
        }
        digits[i] += 1;
        return digits;
    }
};
