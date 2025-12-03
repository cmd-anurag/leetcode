#include<vector>
#include<unordered_map>
#include<map>
using std::vector, std::unordered_map, std::map;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<float, vector<float>> slopeIntercepts;
        int result = 0;

        unordered_map<int, vector<float>> midPointMap;

        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) 
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                float slope, intercept;
                if(x2 == x1) {
                    slope = 1e9 + 7;
                    intercept = x1;
                } else {
                    slope = 1.0 * dy / dx;
                    intercept = 1.0 * (y1 * dx - x1 * dy) / dx;
                }

                int midPointKey = (x1 + x2) * 1e4 + (y1 + y2);
                midPointMap[midPointKey].push_back(slope);
                slopeIntercepts[slope].push_back(intercept);
            }
        }
        for(auto &pair: slopeIntercepts) {
            if(pair.second.size() <= 1) continue;

            map<float, int> mp;
            for(float intercept : pair.second) {
                mp[intercept]++;
            }

            int prev =0;
            for(auto &it : mp) {
                int count =it.second;
                result += count * prev;
                prev += count;
            }
        }

        for(auto &it : midPointMap) {
            if(it.second.size() <= 1) continue;
            map<float, int> mp;
            for(float slope : it.second) {
                mp[slope]++;
            }

            int prev =0;
            for(auto &it : mp) {
                int count =it.second;
                result -= count * prev;
                prev += count;
            }

        }
        return result;
    }
};