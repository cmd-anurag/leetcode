#include<vector>
using std::vector;
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long result = 0;

        int length = 1;
        result += length;

        for(int i = 1; i < n; ++i) {

            if((prices[i-1] - prices[i]) == 1) {
                ++length;
            } else {
                length = 1;
            }
            result += length;

        }
        return result;
        
    }
};