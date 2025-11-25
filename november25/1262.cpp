#include<vector>
using std::vector;
using std::min;


class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;

        for(int x : nums) {
            sum += x;
        }

        int smallestOne = sum;
        int smallestTwo = sum;

        for(int x : nums) {
            if(x % 3 == 1) {
                smallestTwo = min(x +smallestOne, smallestTwo);
                smallestOne = min(smallestOne, x);
            } else if(x % 3 == 2) {
                smallestOne = min(smallestOne, x + smallestTwo);
                smallestTwo = min(smallestTwo, x);
            }
        }

        if(sum % 3 == 0) return sum;
        if(sum % 3 == 1) {
            return sum - smallestOne;
        } 
        if(sum % 3 == 2) {
            return sum - smallestTwo;
        }
        return 0;
    }
};