#include<vector>
#include<queue>
using std::queue;
using std::pair;
using std::vector;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // 1 based flooding order;
        vector<vector<int>> flood;

        flood.push_back({});

        for(auto coords : cells) {
            flood.push_back(coords);
        }

        int low = 0;
        int high = cells.size();

        int result = 0;

        while(low <= high) {
            int middle = low + (high - low) /  2;

            if(canCross(row, col, middle, flood)) {
                low = middle + 1;
                result = middle;
            } else {
                high = middle - 1 ;
            }
        }

        return result;
    }
private:
    bool canCross(int row, int col, int middle, vector<vector<int>> &flood) {
        // 1 indexed grid

        vector<vector<int>> grid(row + 1, vector<int>(col + 1, 0));

        for(int i = 1; i <= middle; ++i) {
            int x = flood[i][0];
            int y = flood[i][1];
            grid[x][y] = 1;
        }

        vector<vector<bool>> visited(row + 1, vector<bool>(col + 1, false));
        queue<pair<int, int>> q;
        
        for(int i = 1; i <= col; i++) {
            if(grid[1][i] == 0) {
                q.push({1, i});
            }
            visited[1][i] = true;
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            if(front.first == row) return true;

            for(auto &dir : directions) {
                int newX = front.first + dir.first;
                int newY = front.second + dir.second;

                if(newX < 1 || newX > row || newY < 1 || newY > col || visited[newX][newY] || grid[newX][newY]) {
                    continue;
                }

                visited[newX][newY] = true;
                q.push({newX, newY});
            }

        }

        return false;

    }
};