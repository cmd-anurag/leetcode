#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;
        int n = colors.size();
        vector<int> indegree(n, 0);

        for(const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            indegree[v]++;
            adj[u].push_back(v);
        }

        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));

        for(int i = 0; i < n; ++i) {
            if(!indegree[i]) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int result = 0;
        int count = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            ++count;
            result = max(result, dp[u][colors[u] - 'a']);

            for(int &neighbor : adj[u]) {
                for(int j = 0; j < 26; ++j) {
                    dp[neighbor][j] = max(dp[neighbor][j], dp[u][j] + (colors[neighbor] - 'a' == j));
                }
                indegree[neighbor]--;
                if(!indegree[neighbor]) {
                    q.push(neighbor);
                }
            }
        }
        if(count < n) return -1;
        return result;
    }
};