#include<iostream>
#include<string>

using namespace std;

int minLength(string s) {
    bool found = false;
    while(true) {
        found = false;
        if(s.empty()) return 0;
            for(int i = 0; i < s.length() -1; ++i) {
                if(s.at(i) == 'A' && s.at(i+1) == 'B') {
                    s.erase(i, 2);
                    found = true;
                    break;
                }
                else if(s.at(i) == 'C' && s.at(i+1) == 'D') {
                    s.erase(i, 2);
                    found = true;
                    break;
                }
            }
            if(!found) {
                break;
            }
        }
    return s.length();
}

int main() {
    
}