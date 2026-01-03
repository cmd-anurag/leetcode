#include<vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> rowStates = {
            {0, 1, 0},
            {0, 1, 2},
            {0, 2, 0},
            {0, 2, 1},
            {1, 0, 1},
            {1, 0, 2},
            {1, 2, 0},
            {1, 2, 1},
            {2, 0, 1},
            {2, 0, 2},
            {2, 1, 0},
            {2, 1, 2},
        };
    const int M = 1e9 + 7;

    int numOfWays(int n) {

        // 0 -> Red
        // 1 -> Yellow
        // 2 -> Green

        // vector<vector<int>> memo(n+1, vector<int>(12, -1));
        // int result = 0;

        // for(int i = 0; i < 12; ++i) {
        //     result = (result + (solve(n, 1, i, memo) % M)) % M;
        // }

        // return result;

        // apparently there is a linear recurrence relation for this??

        if(n == 1) return 12;
        if(n == 2) return 54;

        long long n1 = 54;
        long long n2 = 12;
        long long current = 0;

        for(int count = 2; count < n; ++count) {
            current = ((5 * n1 - 2 * n2) % M + M) % M;
            n2 = n1;
            n1 = current;
        }

        return current;
        

        
    }
private:
    int solve(int n, int row, int prevIndex, vector<vector<int>> &memo) {

        if(row == n) return 1;

        if(memo[row][prevIndex] != -1) return memo[row][prevIndex];

        int result = 0;

        for(int i = 0; i < 12; ++i) {
            if(i == prevIndex) continue;

            vector<int>& prevRow = rowStates[prevIndex];
            vector<int> &currentRow = rowStates[i];

            // check if currentrow can be placed by comparing it to prev row
            bool valid = true;
            for(int j = 0; j < 3; ++j) {
                if(prevRow[j] == currentRow[j]) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                result = (result + (solve(n, row+1, i, memo) % M)) % M;
            }

        }
        return memo[row][prevIndex] = result;
    }
};