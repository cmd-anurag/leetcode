#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                // check row
                for (int column = 0; column < 9; ++column) {
                    if (column == j) continue;
                    if (board[i][column] == board[i][j]) return false;
                }

                // check column
                for (int row = 0; row < 9; ++row) {
                    if (row == i) continue;
                    if (board[row][j] == board[i][j]) return false;
                }

                // check sub-box
                int row = (i/3)*3;
                int column = (j/3)*3;

                for(int x = row; x < row+3; x++) {
                    for(int y = column; y < column+3; ++y) {
                        if(x == i && y == j) continue;
                        if(board[x][y] == board[i][j]) return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '0', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '6', '.', '.', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (s.isValidSudoku(board)) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}