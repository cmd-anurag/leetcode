#include <iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;


class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        vector<string> result;
        
        for(int i = 0; i < s.size(); i += k) {
            string word = "";
            for(int j = i; j < s.size() && j < i+k; ++j) {
                word.push_back(s.at(j));
            }

            result.push_back(word);
        }

        while (result.at(result.size() - 1).size() != k) 
        {
            result.at(result.size() - 1).push_back(fill);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> output = s.divideString("abcdefghi", 1, 'x');
    for(auto s : output) {
        std::cout << s << " ";
    }
}
