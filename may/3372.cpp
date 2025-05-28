#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                               vector<vector<int>> &edges2,
                               int k)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> g1(n), g2(m);
        for (auto &e : edges1)
        {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2)
        {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }

        auto bfs_count = [&](const vector<vector<int>> &g, int src, int maxd)
        {
            vector<char> seen(g.size());
            queue<pair<int, int>> q;
            q.push({src, 0});
            seen[src] = 1;
            int cnt = 1;
            while (!q.empty())
            {
                auto [u, d] = q.front();
                q.pop();
                if (d == maxd)
                    continue;
                for (int w : g[u])
                {
                    if (!seen[w])
                    {
                        seen[w] = 1;
                        cnt++;
                        q.push({w, d + 1});
                    }
                }
            }
            return cnt;
        };

        vector<int> cnt1(n);
        for (int i = 0; i < n; i++)
        {
            cnt1[i] = bfs_count(g1, i, k);
        }

        int best2 = 0;
        if (k > 0)
        {
            for (int b = 0; b < m; b++)
            {
                best2 = max(best2, bfs_count(g2, b, k - 1));
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = cnt1[i] + best2;
        }
        return ans;
    }
};
