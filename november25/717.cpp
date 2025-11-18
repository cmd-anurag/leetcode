#include<vector>
using std::vector;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        bool flag = false;

        while(i < n) {
            if(bits[i] == 0) {
                i++;
                flag = true;
            } else {
                i += 2;
                flag = false; 
            }
        }
        return flag;
    }
};