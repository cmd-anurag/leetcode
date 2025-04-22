#include <vector>
using std::vector, std::max, std::min;

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long long pref = 0, minPref = 0, maxPref = 0;
        for (int d : differences)
        {
            pref += d;
            minPref = min(minPref, pref);
            maxPref = max(maxPref, pref);
        }
        long long low = lower - minPref;
        long long high = upper - maxPref;
        return high >= low ? int(high - low + 1) : 0;
    }
};