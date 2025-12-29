#include<string>
#include<unordered_map>
#include<vector>
using std::vector, std::string, std::unordered_map;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> hash;

        unordered_map<string, bool> memo;

        for(string valid : allowed) {

            string key = valid.substr(0, 2);
            char value = valid[2];

            hash[key].push_back(value);
        }

        string next;
        return solve(bottom, next, hash, memo);
    }

    bool solve(string current, string next, unordered_map<string, vector<char>> &hash, unordered_map<string, bool> &memo) {

        if(next.empty() && memo.find(current) != memo.end()) {
            return memo[current];
        }

        // we reached the top
        if(current.length() == 1) return true;

        // next was successfully built, go for the next level
        if(next.length() == current.length() - 1) {
            return memo[current] = solve(next, "", hash, memo);
        }

        // if i reach here that means next is incomplete and i just placed one of the options of a valid key
        int index = next.size();
        string key = current.substr(index, 2);
        if(hash.find(key) == hash.end()) return false;

        vector<char> options = hash[key];

        for(char option : options) {
            next.push_back(option);
            bool result = solve(current, next, hash, memo);

            if(result) {
                return memo[current] = true;
            } else {
                next.pop_back();
            }
        }
        return memo[current] = false;
    }
};