#include<unordered_set>
using std::unordered_set;

class Solution {
public:
    int countTriples(int n) {
        int count =0;
        unordered_set<int> squares;
        for(int i = 1; i <=n; ++i) {
            squares.insert(i*i);
            // cout << i*i << " ";
        }

        for(int a = 1; a <= n; ++a) {
            for(int b = 1; b <= n; ++b) {
                int lhs = a*a + b*b;

                if(squares.find(lhs) != squares.end()) {
                    ++count;
                }
            }
        }

        return count;
    }
};