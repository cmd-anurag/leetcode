#include<vector>
#include<climits>
#include<algorithm>
using std::abs, std::min;
using std::vector;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long absum = 0;
        int smallest = INT_MAX;
        int negativeCount = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int num = matrix[i][j];
                if(num < 0) negativeCount++;
                absum += abs(num);
                smallest = min(smallest, abs(num));
            }
        }
        
        if(negativeCount & 1) {
            return absum - 2LL * smallest;
        } else {
            return absum;
        }

    }
};