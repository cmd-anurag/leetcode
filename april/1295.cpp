#include <vector>
using std::vector;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int n : nums)
        {
            if (!(countDigits(n) & 1))
                ++count;
        }
        return count;
    }

private:
    int countDigits(int n)
    {
        int count = 0;
        while (n > 0)
        {
            ++count;
            n /= 10;
        }
        return count;
    }
};