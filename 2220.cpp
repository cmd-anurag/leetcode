#include <iostream>

using namespace std;

int minBitFlips(int start, int goal) {
    int result = start^goal;
    int count = 0;
    while(result > 0) {
        if(result % 2 == 1) {
            ++count;
        }
        result /= 2;
    }
    return count;   
}

int main() {
    cout << minBitFlips(31, 0);
}