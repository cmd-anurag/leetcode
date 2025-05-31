#include <vector>
#include <queue>

using std::vector, std::queue, std::pair;

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        int target = n * n;
        auto getValue = [&](int s)
        {
            int r = n - 1 - (s - 1) / n;
            int c = ((s - 1) / n) % 2 == 0 ? (s - 1) % n : n - 1 - (s - 1) % n;
            return board[r][c];
        };
        vector<bool> visited(target + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;
        while (!q.empty())
        {
            auto [s, moves] = q.front();
            q.pop();
            if (s == target)
                return moves;
            for (int d = 1; d <= 6; ++d)
            {
                int next = s + d;
                if (next > target)
                    break;
                int v = getValue(next);
                int dest = (v == -1 ? next : v);
                if (!visited[dest])
                {
                    visited[dest] = true;
                    q.push({dest, moves + 1});
                }
            }
        }
        return -1;
    }
};