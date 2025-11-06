#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using std::vector, std::unordered_map, std::set, std::unordered_set;

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {

        vector<int> compId(c + 1);
        unordered_map<int, set<int>> map;

        unordered_map<int, vector<int>> adj;

        for (auto pair : connections) {
            int u = pair[0];
            int v = pair[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int> visited;
        for(int i = 1; i <= c; ++i) {
            if(visited.find(i) == visited.end()) {
                compId[i] = i;
                dfs(i, adj, visited, compId, i);
            }
        }

        for(int i = 1; i <= c; ++i) {
            int id = compId[i];
            map[id].insert(i);
        }

        vector<int> result;
        for(auto query : queries) {
            int queryType = query[0];
            int node = query[1];

            int componentID = compId[node];
            auto& componentSet = map[componentID]; // future me dont forget this

            // cout << "NODE IS " << node << " " << "compid " << componentID << '\n';
            // for(auto x : componentSet) {
            //     cout << x << " ";
            // }
            // cout << '\n';

            if(queryType == 1) {
                if(componentSet.empty()) {
                    result.push_back(-1);
                }
                else if(componentSet.find(node) != componentSet.end()) {
                    result.push_back(node);
                } else {
                    result.push_back(*componentSet.begin());
                }
            } else {
                // cout << "erasing " << node << '\n'; 
                componentSet.erase(node);
            }
        }
        
        return result;
    }

private:
    void dfs(int start, unordered_map<int, vector<int>>& adj,
             unordered_set<int>& visited, vector<int>& compId, int componentID) 
    {
        visited.insert(start);
        compId[start] = componentID;

        for(auto neighbor : adj[start]) {
            if(visited.find(neighbor) == visited.end()) {
                dfs(neighbor, adj, visited, compId, componentID);
            }
        }

    }
};