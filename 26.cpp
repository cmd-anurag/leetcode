#include <iostream>
#include <vector>

using namespace std;



int removeDuplicates(vector<int>& nums) {
    int count = 1;
    for(int i = 1;i<nums.size(); ++i) {
        if(nums.at(i)!=nums.at(i-1)) {
            nums.at(count) = nums.at(i);
        }
    }
}

void displayList(vector<int>& nums) {
    for(int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    removeDuplicates(nums);
    displayList(nums);
}