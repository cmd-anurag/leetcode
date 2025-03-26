#include<iostream>
#include<string>

using namespace std;

int minSwaps(string s) {
    int opening = 0;
    int closing = 0;
    int maxImbalance = 0;
    for(char c : s) {
        if(c == '[') {
            ++opening;
        }
        else {
            ++closing;
        }
        if(closing - opening > maxImbalance) {
            maxImbalance = closing - opening;
        }
    }
    return (maxImbalance+1)/2;
}