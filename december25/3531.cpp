#include<unordered_map>
#include<vector>
#include<climits>

using std::unordered_map, std::vector, std::pair, std::max, std::min;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        unordered_map<int, pair<int,int>> h;
        unordered_map<int, pair<int, int>> v;

        for(auto coords : buildings) {
            int x = coords[0];
            int y = coords[1];

            if(!h.count(y)) {
                h[y] = {INT_MIN, INT_MAX};
            }
            if(!v.count(x)) {
                v[x] = {INT_MIN, INT_MAX};
            }

            h[y].first = max(x, h[y].first);
            h[y].second = min(x, h[y].second);

            v[x].first = max(y, v[x].first);
            v[x].second = min(y, v[x].second);
        }

        // cout << "Max and Min x on each y: \n"; 
        // for(auto pair : h) {
        //     cout << pair.first << "->" << pair.second.first << " " << pair.second.second << '\n';
        // }

        // cout << "Max and Min y on each x: \n"; 
        // for(auto pair : v) {
        //     cout << pair.first << "->" << pair.second.first << " " << pair.second.second << '\n';
        // }

        int count = 0;

        for(auto coords : buildings) {
            int x = coords[0];
            int y = coords[1];

            bool top = v[x].first > y;
            bool bottom = v[x].second < y;

            bool left = h[y].first > x;
            bool right = h[y].second < x;

            if(top && bottom && left && right) {
                ++count;
            }
        }

        return count;
    }
};