#include<vector>
#include<unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i = 0; i <= n-3; ++i) {
            for(int j = 0; j <= m-3; ++j) {
                if(isMS(grid, i, j)) ++count;
            }
        }
        return count;
    }
private:
    bool isMS(vector<vector<int>> &grid, int i, int j) {
        unordered_set<int> found;
        int target = 15;

        // check rows;
        for(int row = i; row < i + 3; ++row) {
            int rowSum = 0;

            for(int col = j; col < j + 3; ++col) {
                int number = grid[row][col];

                if(number > 9 || number < 1) return false;

                if(found.find(number) != found.end()) return false;

                rowSum += number;
                found.insert(number);
            }

            if(rowSum != target) return false;
        }

        //check cols;
        for(int col = j; col < j + 3; ++col) {
            int colSum = 0;
            for(int row = i; row < i + 3; ++row) {
                colSum += grid[row][col];
            }

            if(colSum != target) return false;
        }

        // check d1
        int row = i;
        int col = j;
        int diagonalSum = 0;
        while(row < i + 3 && col < j + 3) {
            diagonalSum += grid[row][col];
            row++;
            col++;
        }
        if(diagonalSum != target) return false;

        // check d2;
        row = i;
        col = j+2;
        diagonalSum = 0;
        while(row < i + 3 && col >= 0) {
            diagonalSum += grid[row][col];
            row++;
            col--;
        }
        if(diagonalSum != target) return false;

        return true;
    }
};