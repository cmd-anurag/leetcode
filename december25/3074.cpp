#include<vector>
#include<algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int count = 0;
        int totalApples = 0;
        for(int app : apple) {
            totalApples += app;
        }

        sort(capacity.rbegin(), capacity.rend());

        for(int cap: capacity) {
            totalApples -= cap;
            ++count;

            if(totalApples <= 0) break;
        }

        return count;
    }
};