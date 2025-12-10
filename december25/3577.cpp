#include<vector>
using std::vector;
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int result = 1;
        const int M = 1e9 + 7;
        int length = complexity.size() - 1;
        for(int i = 1; i < complexity.size(); ++i) {
            if(complexity[i] <= complexity[0]) {
                return 0;
            } else {
                result = (1LL * result * length) % M;
            }
            length--;
        }
        return result;
    }
};