#include<iostream>
using namespace std;


bool isAnagram(string s, string t) {
        int smap[26] = {};
        int tmap[26] = {};

        if(s.length() != t.length()) return false;

        for(int i = 0; i < t.length(); ++i) {
            char sc = s[i];
            if(smap[sc - 97] == 0) {
                smap[sc - 97] = 1;
            }
            else {
                smap[sc - 97]++;
            }

            char tc = t[i];
            if(tmap[tc - 97] == 0) {
                tmap[tc - 97] = 1;
            }
            else {
                tmap[tc - 97]++;
            }
        }
        for(int i = 0; i < 26; ++i) {
            if(tmap[i] != smap[i]) {
                return false;
            }
        }
        return true;
    }

int main()
{

    string s = "rata";
    string t = "car";
    cout << isAnagram(s, t);
    return 0;
}