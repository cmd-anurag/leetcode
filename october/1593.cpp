#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<string> visited;

    int ans = 1;

    void dfs(string s, int i, int x) {
        
        if(i == s.length()) {
            ans = max(x, ans);
            return;
        }
        for(int j = i+1; j <= s.length(); ++j) {
            string substring = s.substr(i, j-i);
            if(visited.count(substring) == 0) {
                visited.insert(substring);
                dfs(s, j, x+1);
                visited.erase(substring);
            }
        }

    }
    int maxUniqueSplit(string s) {
        dfs(s, 0, 0);
        return ans;
    }
};


int main()
{
    
    return 0;
}