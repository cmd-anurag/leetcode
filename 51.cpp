#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;

        vector<string> board(n, string(n, '.'));
        solve(board, n, 0, result);
        return result;
    }
private:
    void solve(vector<string> &board, int n, int row, vector<vector<string>> &result) 
    {
        if(row >= n) {
            result.push_back(board);
            return;
        }

        for(int column = 0; column < n; ++column) {

            if(isValidSquare(board, row, column, n)) {

                board[row][column] = 'Q';
                solve(board, n, row+1, result);
                board[row][column] = '.';

            }

        }
    }
    bool isValidSquare(vector<string> board, int row, int column, int n) {
        int x = row;
        int y = column;
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 'Q') return false;
            x--;
            y--;
        }
        x = row;
        y = column;
        while(x >= 0 && y < n) {
            if(board[x][y] == 'Q') return false;
            x--;
            y++;
        }
        x = row;
        while(x >= 0) {
            if(board[x][column] == 'Q') return false;
            x--;
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<vector<string>> result = s.solveNQueens(3);

    for(auto solution : result) {
        for(string row : solution) {
            cout << row << '\n';
        }
        cout << "\n\n";
    }
}