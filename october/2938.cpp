#include<iostream>
#include<string>

using namespace std;

long long minimumSteps(string s) {
    long long result = 0;
    int left = 0;
    int right = 0;
    while(right < s.length()) {
        if(s.at(right) == '0') {
            result += right - left;
            ++left;
            ++right;
        }
        else {
            ++right;
        }
    }
    return result;
}

int main()
{
    
    return 0;
}