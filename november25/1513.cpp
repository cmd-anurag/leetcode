#include<string>
using std::string;

class Solution {
public:
    int numSub(string s) {
        int MOD = 1e9 + 7;

        int n = s.length();
        long long length = 0;
        int result = 0;
        bool flag = false;

        for(int i = 0; i < n; ++i) {

            if(s[i] == '1') {
                if(flag) {
                    ++length;
                } else {
                    flag = true;
                    length = 1;
                }
            } else {
                result += (((length * (length + 1)) % MOD ) / 2) % MOD;
                flag = false;
                length = 0;
            }
        }
        if(length) {
            result += ((length * (length + 1)) / 2) % MOD;
        }

        return result;
    }
};