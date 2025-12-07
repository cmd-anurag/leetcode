class Solution {
public:
    int countOdds(int low, int high) {
        int total = high - low + 1;
        int result = total / 2;
        if(low & 1 && high & 1) {
            return result + 1;
        }
        return result;
    }
};