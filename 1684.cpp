#include <vector>
#include <string>

using namespace std;

// RETRY using bit masks

class Solution {
public:

    bool isPresent(string allowed, char c) {
        for(char l : allowed) {
            if(l == c) {
                return true;
            }
        }
        return false;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        bool consistent = true;

        for(string word : words) {
            consistent = true;
            for(char letter : word) {
                if(!isPresent(allowed, letter)) {
                    consistent = false;
                }
            }
            if(consistent) ++count;
        }
        return count;
    }
};

