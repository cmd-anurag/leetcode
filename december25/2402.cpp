#include<vector>
#include<queue>
#include<algorithm>
using std::sort;
using std::vector;
using std::priority_queue;
using std::greater;
using std::pair;

bool compare(const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; }

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end(), compare);
        vector<int> roomUses(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busyRooms;
        priority_queue<int, vector<int>, greater<int>> freeRooms;

        for(int i = 0; i < n; ++i) {
            freeRooms.push(i);
        }

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];

            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();

                busyRooms.push({end, room});
                roomUses[room]++;
            } else {
                auto roomObj = busyRooms.top();
                busyRooms.pop();

                long long duration = end - start;
                long long newEnd = roomObj.first + duration;

                busyRooms.push({newEnd, roomObj.second});
                roomUses[roomObj.second]++;
            }
        }

        int resultIndex = -1;
        int result = 0;

        for(int i = 0; i < n; ++i) {
            if(roomUses[i] > result) {
                resultIndex = i;
                result = roomUses[i];
            }
        }

        return resultIndex;
    }
};