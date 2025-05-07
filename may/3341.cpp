#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Solution
{
public:
    typedef pair<int, pair<int, int>> P;

    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int m = moveTime.size();
        int n = moveTime.at(0).size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        std::priority_queue<P, vector<P>, std::greater<P>> pq;

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            int currentTime = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;

            pq.pop();

            if (i == m - 1 && j == n - 1)
            {
                return currentTime;
            }
            for (auto &dir : directions)
            {
                int di = i + dir[0];
                int dj = j + dir[1];

                if (di >= 0 && di < m && dj >= 0 && dj < n)
                {
                    int waitTime = max(moveTime[di][dj] - currentTime, 0);
                    int newTime = currentTime + waitTime + 1;

                    if (result[di][dj] > newTime)
                    {
                        result[di][dj] = newTime;
                        pq.push({newTime, {di, dj}});
                    }
                }
            }
        }

        return -1;
    }
};