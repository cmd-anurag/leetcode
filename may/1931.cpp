#include <string>
#include <vector>
using std::vector;
using std::string;

/**
 * @class Solution
 * @brief Computes the number of valid colorings of an m x n grid using 3 colors (R, G, B)
 *        such that no two adjacent cells in any row or column share the same color.
 * @link https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/ @endlink
 */
class Solution {
public:
    const int MOD = 1e9 + 7; ///< Modulo constant for large results.
    vector<vector<int>> temp; ///< DP memoization table: temp[remainingCols][prevIndex].

    /**
     * @brief Entry point to calculate the number of valid grid colorings.
     *
     * Generates all valid single-column color states of height `m`, and uses
     * memoized recursion to compute valid arrangements of `n` columns.
     *
     * @param m Number of rows in the grid.
     * @param n Number of columns in the grid.
     * @return Total number of valid colorings modulo 1e9+7.
     */
    int colorTheGrid(int m, int n) {
        generateStates("", ' ', 0, m);
        int totalStates = columnStates.size();

        temp = vector<vector<int>>(n + 1, vector<int>(totalStates + 1, -1));

        int result = 0;
        for (int i = 0; i < columnStates.size(); ++i) {
            result = (result + solve(n - 1, i, m)) % MOD;
        }

        return result;
    }

private:
    vector<string> columnStates; ///< Stores all valid color states for one column.

    /**
     * @brief Recursively generates all valid column color combinations of height `rows`.
     *
     * A column state is valid if no two adjacent cells in it have the same color.
     *
     * @param currentState Current partial string representing column color configuration.
     * @param prevChar Previously used character in the current string.
     * @param currentLength Current length of the constructed string.
     * @param rows Target column height.
     */
    void generateStates(string currentState, char prevChar, int currentLength, int rows) {
        if (currentLength == rows) {
            columnStates.push_back(currentState);
            return;
        }

        for (char ch : {'R', 'G', 'B'}) {
            if (ch == prevChar) continue;
            generateStates(currentState + ch, ch, currentLength + 1, rows);
        }
    }

    /**
     * @brief Recursively computes number of ways to color remaining columns.
     *
     * A valid column coloring must differ from the previous column at every cell.
     *
     * @param remainingCols Number of columns left to color.
     * @param prevIndex Index of the last used column state.
     * @param rows Number of rows in the grid.
     * @return Number of valid colorings from this state onward.
     */
    int solve(int remainingCols, int prevIndex, int rows) {
        if (remainingCols == 0) return 1;

        if (temp[remainingCols][prevIndex] != -1) {
            return temp[remainingCols][prevIndex];
        }

        int ways = 0;
        string prevState = columnStates[prevIndex];

        for (int i = 0; i < columnStates.size(); ++i) {
            if (i == prevIndex) continue;

            string currentState = columnStates[i];
            bool valid = true;

            for (int j = 0; j < rows; j++) {
                if (prevState[j] == currentState[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ways = (ways + solve(remainingCols - 1, i, rows)) % MOD;
            }
        }

        temp[remainingCols][prevIndex] = ways;
        return ways;
    }
};