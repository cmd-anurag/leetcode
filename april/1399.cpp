#include <unordered_map>

class Solution
{
public:
    int countLargestGroup(int n)
    {
        std::unordered_map<int, int> hash;

        for (int i = 1; i <= n; ++i)
        {
            int sumOfDigits = sumDigits(i);
            hash[sumOfDigits]++;
        }

        int maxFrequency = 0;
        int count = 0;

        for (const auto &it : hash)
        {
            if (it.second > maxFrequency)
            {
                count = 1;
                maxFrequency = it.second;
                continue;
            }
            if (it.second == maxFrequency)
            {
                ++count;
            }
        }

        return count;
    }

private:
    int sumDigits(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};