#include<vector>
#include<string>
using std::vector, std::string;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for(int i = 0; i < words.size(); ++i) {
            for(char character : words[i]) {
                if(character == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};