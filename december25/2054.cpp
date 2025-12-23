#include<vector>
#include<algorithm>
using std::sort, std::vector;
using std::max;

bool compare(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), compare);
        vector<vector<int>> memo(n, vector<int>(2, -1));

        vector<vector<int>> dp(n+1, vector<int>(3, 0));;

        for(int i = n-1; i >= 0 ; --i) {
            for(int count = 1; count >= 0; --count) {
                int start = events[i][0];
                int end = events[i][1];
                int value = events[i][2];
                int nextValidIndex = getNextValidIndex(events, i+1, end);
                int take = 0;
                if(nextValidIndex == -1) {
                    take = value;
                } else {
                    take = value + dp[nextValidIndex][count + 1];
                }
                int leave = dp[i+1][count];

                dp[i][count] = max(take, leave);
                
            }
        }

        return dp[0][0];
        // return solve(events, 0, 0, memo);
    }
private:
    int solve(vector<vector<int>> &events, int i, int count, vector<vector<int>> &memo) {
        if(i >= events.size()) return 0;

        if(count >= 2) {
            return 0;
        }

        if(memo[i][count] != -1) return memo[i][count];

        int start = events[i][0];
        int end = events[i][1];
        int value = events[i][2];

        int nextValidIndex = getNextValidIndex(events, i + 1, end);

        int take = value + solve(events, nextValidIndex, count + 1, memo);
        int leave = solve(events, i+1, count, memo);

        return memo[i][count] = max(take, leave);

    }
    int getNextValidIndex(vector<vector<int>> &events, int i, int end) {
        int left = i;
        int right = events.size() - 1;
        int result = -1;

        while(left <= right) {
            int middle = left + (right - left) / 2;

            auto &targetEvent = events[middle];
            int targetStart = targetEvent[0];       

            if(targetStart > end) {
                // all events right to it are valid
                result = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return result;
    }
};