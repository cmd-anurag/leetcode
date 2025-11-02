#include<vector>
using std::vector;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<char>> grid(m, vector<char>(n, 'N'));

        for(auto guard : guards) {
            int x = guard[0];
            int y = guard[1];
            grid[x][y] = 'G';
        }
        for(auto wall : walls) {
            int x = wall[0];
            int y = wall[1];
            grid[x][y] = 'W';
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {

                if(grid[i][j] == 'G') {
                    // north
                    int x = i - 1;
                    int y = j;
                    while(x >= 0 && grid[x][y] != 'G' && grid[x][y] != 'W') {
                        grid[x][y] = 'Y';
                        x--;
                    }
                    //south
                    x = i + 1;
                    y = j;

                    while(x < m && grid[x][y] != 'G' && grid[x][y] != 'W') {
                        grid[x][y] = 'Y';
                        x++;
                    }

                    //east
                    x = i;
                    y = j + 1;
                    while(y < n && grid[x][y] != 'G' && grid[x][y] != 'W') {
                        grid[x][y] = 'Y';
                        y++;
                    }
                    // west
                    x = i; 
                    y = j - 1;
                    while(y >= 0 && grid[x][y] != 'G' && grid[x][y] != 'W') {
                        grid[x][y] = 'Y';
                        y--;
                    }
                    y = j;
                    
                }

            }
        }

        int count = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 'N') ++count;
                // cout << grid[i][j] << " ";
            }
            // cout << '\n';
        }

        return count;

    }
};