#include <unordered_map>
#include <vector>
using std::unordered_map, std::vector;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> hash;

        for (int x : answers)
        {
            hash[x]++;
        }

        int result = 0;

        for (auto answer : hash)
        {
            int k = answer.first;
            int count = answer.second;

            int numOfGroups = (count + k) / (k + 1);
            result += (k + 1) * numOfGroups;
        }
        return result;
    }
};