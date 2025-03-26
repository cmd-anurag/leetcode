#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), result = 0;
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        for (int row = 0; row < m; ++row)
            result = max(result, dfs(grid, row, 0, memo));
        
        return result;
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& memo) {
        if (col == grid[0].size() - 1) return 0;
        if (memo[row][col] != -1) return memo[row][col];

        int maxMoves = 0;
        vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};

        for (auto [dr, dc] : directions) {
            int newRow = row + dr, newCol = col + dc;
            if (newRow >= 0 && newRow < grid.size() && newCol < grid[0].size() && grid[newRow][newCol] > grid[row][col]) {
                maxMoves = max(maxMoves, 1 + dfs(grid, newRow, newCol, memo));
            }
        }

        return memo[row][col] = maxMoves;
    }
};

int main() {
    
}