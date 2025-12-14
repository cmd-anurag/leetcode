#include<vector>
#include<string>
using std::string;
using std::vector;

// class Solution {
// public:
//     int M = 1e9 + 7;
//     int numberOfWays(string corridor) {
//         int n = corridor.length();
//         if(n < 2) return 0;
//         int sc =0;
//         for(char c : corridor) {
//             if(c == 'S') sc++;
//         }
//         if(sc & 1 || sc == 0) return 0;

//         vector<vector<int>> memo(n, vector<int>(3, -1));

//         return solve(corridor, 0, 0, memo);
//     }
// private:
//     int solve(string &corridor, int i, int seatCount, vector<vector<int>> &memo) {
//         if(i >= corridor.size()) {
//             return 1;
//         }

//         if(memo[i][seatCount] != -1) {
//             return memo[i][seatCount];
//         }

//         if(corridor[i] == 'S') ++seatCount;

//         if(seatCount == 2) {
//             int temp = i+1;
//             int count = 0;
//             while(temp < corridor.size() && corridor[temp] == 'P') {
//                 ++count;
//                 ++temp;
//             }
//             if(temp == corridor.size()) return 1;

//             long long ways = 1LL * (count + 1) * solve(corridor, temp, 0, memo) % M;
//             memo[i][seatCount] = ways;
//             return ways;
//         }

//         long long ways = solve(corridor, i+1, seatCount, memo) % M;
//         memo[i][seatCount] = ways;
//         return ways;

//     }
// };

class Solution {
public:
    int numberOfWays(string corridor) {

        const int M = 1e9 + 7;

        int n = corridor.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        dp[n][2] = 1;

        int seatCount = 0;

        for(char c : corridor) {
            if(c == 'S') ++seatCount;
        }
        if(seatCount == 0 || seatCount & 1) return 0;

        seatCount = 0;
        for(int i = n-1; i>= 0;i--) {

            for(int seatCount = 0; seatCount <= 1; ++seatCount) {
                int currentSeats = seatCount;
                if(corridor[i] == 'S') {
                    ++currentSeats;
                }

                if(currentSeats == 2) {
                    int temp= i+1;
                    int count = 0;
                    while(temp < n && corridor[temp] == 'P') {
                        ++count;
                        ++temp;
                    }
                    if(temp == n) {
                        dp[i][seatCount] = 1;
                    } else {
                        long long ways = 1LL * (count + 1) * dp[temp][0] % M;
                        dp[i][seatCount] = ways;
                    }
                } else {
                    long long ways = dp[i+1][currentSeats];
                    dp[i][seatCount] = ways;
                }

            }
            
        }

        return dp[0][0];
    }
};