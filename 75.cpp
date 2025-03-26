#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int hashMap[3] = {};
        for(int i : nums) {
            if(i == 0) {
                hashMap[0]++;
            }
            else if(i == 1) {
                hashMap[1]++;
            }
            else {
                hashMap[2]++;
            }
        }

        int index = 0;

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < hashMap[i]; ++j) {
                nums[index++] = i;
            }
        }
    }
};

int main() {

}