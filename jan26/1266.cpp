#include<vector>
#include<algorithm>
using std::vector, std::abs, std::max, std::min, std::pair;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        pair<int, int> currentPosition = {points[0][0], points[0][1]};

        for(int i = 1; i < points.size(); ++i) {
            pair<int, int> destination = {points[i][0], points[i][1]};

            int dx = abs(destination.first - currentPosition.first);
            int dy = abs(destination.second - currentPosition.second);
            
            time += min(dx, dy); // diagonal movement

            if(dx != dy) {
                time += abs(dy - dx); // horizontal or vertical
            }

            currentPosition = destination;
            
        }

        return time;
    }
};