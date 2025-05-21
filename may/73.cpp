#include<vector>
using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // using extra space

        // 1. Simply create a new 2d matrix and build it cell by cell, if a zero is encoutered modify its row and column
        // O(mn) space

        // 2. A slight improvement could be to store only the row and columns where a zero has been found
        // O(m+n) space

        int n = matrix.size();
        int m = matrix.at(0).size();

        vector<bool> rows(n, false);
        vector<bool> columns(m, false);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(!matrix[i][j]) {
                    rows[i] = true;
                    columns[j] = true;
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(rows[i] || columns[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};