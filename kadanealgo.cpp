#include <iostream>
#include <vector>
#include <cstdint>



using namespace std;



int main() {
    vector<int> nums = {-2, 1, 3, -1, 2};
    int n = nums.size();
    int startIndex = 0, endIndex = 0;
    int sum = 0;
    int max = INT32_MIN;
    for(int i = 0; i < n; ++i) {
        sum += nums.at(i);
        if(sum > max) {
            max = sum;
            endIndex = i;
        }
        if(sum < 0) {
            startIndex = i+1;
            sum = 0;
        }
    }
    cout << max << endl;
    cout << startIndex << " to " << endIndex;
}