#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int k = queries.size();
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<pair<int, int>> newQueries;

        for (int i = 0; i < k; ++i)
        {
            newQueries.push_back({queries[i], i});
        }

        sort(newQueries.begin(), newQueries.end());

        vector<int> result(k);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        visited[0][0] = true;

        int points = 0;
        for (auto [q, originalIndex] : newQueries)
        {

            while (!minHeap.empty())
            {
                auto [value, i, j] = minHeap.top();

                if (value < q)
                {
                    minHeap.pop();
                    ++points;
                }
                else
                {
                    break;
                }

                if (i - 1 >= 0 && !visited[i - 1][j])
                {
                    minHeap.push({grid[i - 1][j], i - 1, j});
                    visited[i - 1][j] = true;
                }

                if (j - 1 >= 0 && !visited[i][j - 1])
                {
                    minHeap.push({grid[i][j - 1], i, j - 1});
                    visited[i][j - 1] = true;
                }

                if (i + 1 < ROWS && !visited[i + 1][j])
                {
                    minHeap.push({grid[i + 1][j], i + 1, j});
                    visited[i + 1][j] = true;
                }
                if (j + 1 < COLS && !visited[i][j + 1])
                {
                    minHeap.push({grid[i][j + 1], i, j + 1});
                    visited[i][j + 1] = true;
                }
            }

            result[originalIndex] = points;
        }

        return result;
    }
};