#include<unordered_set>
#include<iostream>
using namespace std;

bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);


        while(n != 1) {
            int temp = n;
            int sum = 0;
            while(temp > 0) {
                int digit = temp%10;
                sum += digit*digit;
                temp /= 10;
            }
            n = sum;
            if(s.find(n) != s.end()) {
                return false;
            }
            else {
                s.insert(n);
            }
        }
        return true;
    }