#include<unordered_map>
#include<vector>
using std::unordered_map, std::vector;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1e9 + 7;

        unordered_map<int, int> groups;

        for(auto pair : points) {
            int y = pair[1];
            groups[y]++;
        }

        int result = 0;

        int totalLines = 0;

        for(auto pair : groups) {
            int y = pair.first;
            int count = pair.second;

            long long currentLines = 1LL * count * (count - 1) / 2;
            currentLines %= MOD;
            long long mul = currentLines * totalLines;

            result = (result + mul) % MOD;
            totalLines += currentLines % MOD;
        }
        // FFS
        return result;
    }
};