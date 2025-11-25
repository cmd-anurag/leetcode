class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n = 1;
        int num = 1;

        if(k % 2 == 0 || k % 5 == 0) { 
            // since the number always ends with 1, it wont be divisible by multiple of 2 or 5
            return -1;
        }

        while(n <= k) {
            if(num % k == 0) return n;
            num = (num*10 + 1) % k;
            n++;
        }
        return -1;
    }
};