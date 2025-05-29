#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        g1.assign(n, {});
        g2.assign(m, {});
        for (auto& e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }
        f1.assign(n, {0, 0});
        dp1.assign(n, {0, 0});
        f2.assign(m, {0, 0});
        dp2.assign(m, {0, 0});

        dfsCompute(0, -1, g1, f1);
        dp1[0] = f1[0];
        dfsReroot(0, -1, g1, f1, dp1);

        dfsCompute(0, -1, g2, f2);
        dp2[0] = f2[0];
        dfsReroot(0, -1, g2, f2, dp2);

        int best2 = 0;
        for (auto& p : dp2)
            best2 = max(best2, p.second);

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = dp1[i].first + best2;
        return ans;
    }

private:
    vector<vector<int>> g1, g2;
    vector<pair<int, int>> f1, dp1, f2, dp2;

    void dfsCompute(int u, int p, vector<vector<int>>& g,
                    vector<pair<int, int>>& f) {
        f[u] = {1, 0};
        for (int v : g[u])
            if (v != p) {
                dfsCompute(v, u, g, f);
                f[u].first += f[v].second;
                f[u].second += f[v].first;
            }
    }

    void dfsReroot(int u, int p, vector<vector<int>>& g,
                   vector<pair<int, int>>& f, vector<pair<int, int>>& dp) {
        for (int v : g[u])
            if (v != p) {
                int outEven = dp[u].second - f[v].first;
                int outOdd = dp[u].first - f[v].second;
                dp[v].first = f[v].first + outEven;
                dp[v].second = f[v].second + outOdd;
                dfsReroot(v, u, g, f, dp);
            }
    }
};
