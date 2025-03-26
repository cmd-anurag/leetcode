// TIME LIMIT EXCEEDED

#include <iostream>
#include <vector>

using namespace std;

// BRUTE FORCE

// vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//     vector<int> answer;

//     int xorresult;
//     for(int i = 0; i < arr.size(); ++i) {
//         xorresult = 0;
//         for(int j = queries[i][0]; j <= queries[i][1]; ++j) {
//                 xorresult ^= arr.at(j);
//         }
//         answer.push_back(xorresult);
//     }
//     return answer;
// }

// XOR Prefix 

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> prefix = {0};
    vector<int> answer;

    for(int i = 0; i < arr.size(); ++i) {
        prefix.push_back(arr[i]^prefix.back());
    }

    int left;
    int right;

    for(int i = 0; i < queries.size(); ++i) {
        left = queries[i][0];
        right = queries[i][1];
        answer.push_back(prefix[right + 1] ^ prefix[left]);
    }
    return answer;
}

int main() {
    vector<int> arr = {4,8,2,10};
    vector<vector<int>> queries = {{2,3}, {1,3}, {0,0}, {0, 3}};

    vector<int> answer = xorQueries(arr, queries);
    for(int i : answer) {
        cout << i << " ";
    }

}