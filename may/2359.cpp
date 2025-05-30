#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        const int INF = numeric_limits<int>::max();
        
        auto computeDist = [&](int start){
            vector<int> dist(n, INF);
            queue<int> q;
            dist[start] = 0;
            q.push(start);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                int v = edges[u];
                if (v != -1 && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            return dist;
        };
        
        auto dist1 = computeDist(node1);
        auto dist2 = computeDist(node2);
        
        int bestNode = -1;
        int bestMaxDist = INF;
        
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INF && dist2[i] != INF) {
                int currMax = max(dist1[i], dist2[i]);
                if (currMax < bestMaxDist || (currMax == bestMaxDist && i < bestNode)) {
                    bestMaxDist = currMax;
                    bestNode = i;
                }
            }
        }
        
        return bestNode;
    }
};