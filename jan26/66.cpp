#include<vector>
#include<algorithm>
using std::vector;
using std::reverse;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;

        int i = digits.size() - 1;
        while(i >= 0 && digits[i] == 9) {
            result.push_back(0);
            i--;
        }
        
        if(i >= 0) {
            result.push_back(digits[i] + 1);
            i--;
        } else if(i == -1) {
            result.push_back(1);
        }
        
        while(i >= 0) {
            result.push_back(digits[i]);
            i--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};