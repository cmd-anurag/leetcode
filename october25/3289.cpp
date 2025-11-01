#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size(); // use -n as our special marker for 0

        for(int i = 0; i < n; ++i) {
            
            // 1. Get the value we are processing. This value
            // tells us which index to check.
            int value = abs(nums[i]);
            
            // If the value we just read is 'n', it means
            // we are reading our special marker. A marker
            // at nums[i] means the original value there was 0.
            // So, the value we are processing is 0.

            if (value == n) {
                value = 0; 
            }
            
            // 3. 'value' is now the index we need to check/mark.
            int indexToMark = value;
            int targetElement = nums[indexToMark];

            // 4. Now we check the element at that index.
            
            if (targetElement == 0) {
                // We're seeing 'value' for
                // the first time, and its corresponding index
                // (indexToMark) holds a 0. We can't make it
                // negative, so we set it to our special marker -n.
                nums[indexToMark] = -n;
            }
            else if (targetElement > 0)
            {
                // This is the standard case. We're seeing 'value'
                // for the first time. Mark it as seen.
                nums[indexToMark] = -targetElement;
            }
            else if (targetElement < 0) {
                // This spot is already negative (either -num or -n).
                // This means we have seen 'value' before.
                // Therefore, 'value' is a duplicate.
                result.push_back(value);
            }
        }

        return result;
    }
};