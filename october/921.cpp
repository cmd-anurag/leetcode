#include<iostream>
using namespace std;

int minAddToMakeValid(string s) {
    if(s.empty()) {
        return 0;
    }
    int opening = 0;
    int closing = 0;
    int result = 0;
    for(char c : s) {
        if(c == '(') {
            ++opening;
            ++result;
        }
        else {
            if(opening > 0) {
                --result;
                --opening;
            }
            else {
                ++closing;
                ++result;
            }
        }
    }
    return result;
}


int main()
{
    
    return 0;
}