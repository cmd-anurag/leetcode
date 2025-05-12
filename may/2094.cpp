#include<vector>
using std::vector;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;

        vector<int> map(10, 0);
        for(int digit : digits) {
            map[digit]++;
        }

        for(int i = 100; i < 1000; i += 2) {
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;

            vector<int> count(10, 0);
            count[a]++;
            count[b]++;
            count[c]++;

            bool valid = true;

            for(int i = 0; i < 10; ++i) {
                if(count[i] > map[i]) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                result.push_back(i);
            }
        }

        return result;

    }
};