#include<vector>
#include<algorithm>
using std::vector;


bool compare(const vector<int>& a, const vector<int> &b) {
    if (a[1] != b[1]) {
        return a[1] < b[1];
    }
    return a[0] > b[0];
}

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), compare);

        int count = 2;
        int last = intervals[0][1];
        int secondLast = intervals[0][1] - 1;   

        for(int i = 1; i < n; ++i) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(secondLast < start && start <= last) {
                count++;
                secondLast = last;
                last = end;
            } else if (start > last) {
                count += 2;
                last = end;
                secondLast = end - 1;
            }
        }
        return count;
    }
};