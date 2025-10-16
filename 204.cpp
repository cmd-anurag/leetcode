#include<vector>
using std::vector;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1, true);
        primes[0] = false;
        primes[1] = false;
        primes[n] = false;

        for(int i = 2; i*i <= n; ++i) {
            if(primes[i]) {
                for(int j = i*i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }

        int count = 0;

        for(bool flag : primes) {
            if(flag) {
                count++;
            }
        }

        return count;
    }
};