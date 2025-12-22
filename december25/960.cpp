#include<vector>
#include<string>
using std::string;
using std::vector;
using std::max;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs.at(0).size();

        vector<int> dp(m+1, 1);
        int lis = 1;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < i; ++j) {
                bool flag = true;

                for(int row = 0; row < n; ++row) {

                    if(strs[row][j] > strs[row][i]) {
                        flag = false; 
                        break;
                    }
                }

                if(flag) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

                lis = max(dp[i], lis);

            }
        }

        return m - lis;
    }
};