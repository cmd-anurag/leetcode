#include<vector>
using std::vector;
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for(int x : nums) {
            result += getSum(x);
        }

        return result;
    }
private:
    int getSum(int x) {
        int sum = 1 + x;
        int count = 2;

        for(int i = 2; i * i <= x; ++i) {
            if(x % i == 0) {
                int firstDivisor = i;
                int secondDivisor = x / i;

                if(firstDivisor == secondDivisor) {
                    count++;
                    sum += firstDivisor;
                } else {
                    count += 2;
                    sum += firstDivisor + secondDivisor;
                }
            }
        }

        return count == 4? sum : 0;
    }
};