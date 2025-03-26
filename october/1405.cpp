#include<queue>
#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<tuple<int, char>> maxHeap;
        
        if(a != 0) {
            maxHeap.push({a, 'a'});
        }
        if(b != 0) {
            maxHeap.push({b, 'b'});
        }
        if(c != 0) {
            maxHeap.push({c, 'c'});
        }

        vector<char> result(a+b+c);
        int k = 0;
        while(!maxHeap.empty()) {
            
            auto [amount, maxLetter] = maxHeap.top();
            if(k > 1 && result[k-1] == maxLetter && result[k-2] == maxLetter) {
                auto [amount, maxLetter] = maxHeap.top();
                maxHeap.pop();
                if(maxHeap.empty()) break;

                auto[samount, secondMax] = maxHeap.top();
                maxHeap.pop();
                result[k++] = secondMax;
                --samount;
                if(samount > 0) {
                    maxHeap.push({samount, secondMax});
                }
                maxHeap.push({amount, maxLetter});
            }
            else {
                maxHeap.pop();
                result[k++] = maxLetter;
                
                --amount;
                if(amount > 0) {
                    maxHeap.push({amount, maxLetter});
                }
            }
        }
        string r;
        for(char c : result) {
            if(c=='\u0000') break;
            r+=c;
        }
        return r;
    }
};

int main() {
    
}