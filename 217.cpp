#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    
    unordered_map<int, int> hash;

    for(int i : nums) {
        if(hash.count(i) > 0) {
            hash[i] += 1;
        }
        else {
            hash[i] = 1;
        }
        if(hash[i] >= 2) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1};
    cout << containsDuplicate(nums) << '\n';
}