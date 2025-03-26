#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string>> result;

    unordered_map<string, vector<string>> hash;


    for(string s : strs) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());

        hash[sorted].push_back(s);
        
    }

    for(auto x : hash) {
        vector<string> list;
        for(auto y : x.second) {
            list.push_back(y);
        }
        result.push_back(list);
    }
    return result;

}
int main() {
    vector<string> vec = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams(vec);
    for(auto i : result) {
        for(auto j : i) {
           cout << j << " ";
        }
        cout << endl;
    }
}