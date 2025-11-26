#include<vector>
using std::vector;

// Top Down Memoization

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0, 0, 0, grid, k, m ,n, memo);
    }
private:
    int solve(int i, int j, int sum, vector<vector<int>> &grid, int k, int m, int n, vector<vector<vector<int>>> &memo) {
        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) {
            if((sum + grid[i][j]) % k == 0) {
                
                return 1;

            } else {

                return 0;

            }
        }

        int currSum = (sum + grid[i][j]) % k;

        if(memo[i][j][sum] != -1) return memo[i][j][sum];

        int right = solve(i, j+1, currSum, grid, k, m, n, memo);
        int down = solve(i + 1, j, currSum, grid, k, m, n, memo);


        int ans = (right + down) % MOD;
        memo[i][j][sum] = ans;
        return ans;
    }
};