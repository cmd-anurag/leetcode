#include <unordered_map>
#include <vector>
using std::unordered_map, std::vector;

class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        unordered_map<int, vector<int>> adj;

        for (auto pair : edges)
        {
            int u = pair[0];
            int v = pair[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        vector<bool> visited(n, false);
        visited[0] = true;
        dfs(adj, visited, values, count, k, 0, n);
        return count;
    }

private:
    int dfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<int> &values, int &count, int k, int i, int n)
    {

        int sum = values[i];

        for (auto neighbor : adj[i])
        {

            if (!visited[neighbor])
            {

                visited[neighbor] = true;
                sum += dfs(adj, visited, values, count, k, neighbor, n);
                sum %= k;
            }
        }
        sum %= k;
        if (sum == 0)
        {
            count++;
        }

        return sum;
    }
};