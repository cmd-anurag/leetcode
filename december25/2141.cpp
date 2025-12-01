#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// class Solution {
// public:
//     long long maxRunTime(int n, vector<int>& batteries) {
//         long long result = 0;
//         priority_queue<int> maxHeap(batteries.begin(), batteries.end());

//         while (true)
//         {
//             int count = 0;
//             vector<int> extracted;
//             extracted.reserve(n);

//             while(!maxHeap.empty() && count < n) {
//                 int top = maxHeap.top();
//                 if(top <= 0) return result;
//                 extracted.push_back(top);
//                 ++count;
//                 maxHeap.pop();
//             }

//             for(int x : extracted) {
//                 maxHeap.push(x-1);
//             }
//         }

//         return 0;
//     }
// }; // too slow i guess

// try binary search on answer itself


class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for(int x : batteries) {total += x;}
        
        long long high = total / n;
        long long low = 1;

        long long result = low;

        while(low <= high) {
            long long middle = low + (high - low) / 2;

            // check if middle answer is possible
            if(isPossible(middle, batteries, n)) {
                result = middle;
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }

        return result;
    }
private:
    bool isPossible(long long middle, vector<int> &batteries, int n) {
        long long required = middle * n;
        long long total = 0;

        for(long long x : batteries) {
            total += min(x, middle); // i want to check if this battery can power a computer for middle minutes, any extra capacity is wasted and should not be counted towards total.
            if(total >= required) return true;
        }
        return false;
    }
};