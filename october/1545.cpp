#include<iostream>
#include<string>

using namespace std;


class Solution {
public:

    string invert(string s) {
        string res = "";
        for(char i : s) {
            if(i == '1') {
                res+="0";
            }
            else {
                res+="1";
            }
        }
        return res;
    }

    string rev(string s) {
        string res = "";
        for(int i = s.length()-1; i >= 0; --i) {
            res += s[i];
        }
        return res;
    }

    char findKthBit(int n, int k) {
       string result = "0";
       int strIdx = 1;
       for(int i = 1; i < n; ++i) {
            string inverted = invert(result);
            string reversed = rev(inverted);
            result += "1" + reversed;
       }

       return result[k-1];
    }
};

int main() {

}