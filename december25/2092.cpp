#include<queue>
#include<vector>
#include<climits>
using std::priority_queue;
using std::vector;
using std::greater;
using std::pair;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(const auto &meeting : meetings) {
            adj[meeting[0]].push_back({meeting[1], meeting[2]});
            adj[meeting[1]].push_back({meeting[0], meeting[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> minTime(n, INT_MAX);
        
        pq.push({0, 0});
        pq.push({0, firstPerson});
        minTime[0] = 0;
        minTime[firstPerson] = 0;

        while(!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();
            if(time > minTime[person]) continue;

            for(auto& [neighbor, meetingTime] : adj[person]) {
                if(meetingTime >= time) {
                    if(minTime[neighbor] > meetingTime) {
                        minTime[neighbor] = meetingTime;
                        pq.push({meetingTime, neighbor});
                    }
                }
            }
        }

        vector<int> result;
        for(int i = 0; i < n; ++i) {
            if(minTime[i] != INT_MAX) result.push_back(i);
        }
        return result;
    }
};