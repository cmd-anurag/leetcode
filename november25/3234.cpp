// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         // brute force

//         int n = s.size();

//         int arr[2];

//         int count = 0;

//         for(int i = 0; i < n; ++i) {
//             arr[0] = 0;
//             arr[1] = 0;

//             for(int j = i; j < n; ++j) {

//                 if(s[j] == '0') arr[0]++;
//                 else arr[1]++;

//                 if(arr[1] >= arr[0] * arr[0]) ++count;
//             }

//         }

//         return count;
//     }
// };
#include<string>
#include<vector>
using std::string, std::vector;
using std::min;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> nextZero(n, n);

        for(int i = n - 2; i>=0; --i) {
            if(s[i + 1] == '0') {
                nextZero[i] = i+1;
            } else {
                nextZero[i] = nextZero[i+1];
            }
        }

        int result = 0;

        for(int left = 0; left < n; ++left) {
            int zeroes = s[left] == '0'? 1 : 0;
            int right = left;

            while(zeroes * zeroes <= n) {
                int next = right < n? nextZero[right] : n;
                int ones = next - left - zeroes;

                if(ones >= zeroes * zeroes) result += min(next - right, ones - zeroes * zeroes + 1);

                right = next;
                zeroes++;
                if(right == n) break;
            }

        }
        return result;
    }
};

// medium question 🤡