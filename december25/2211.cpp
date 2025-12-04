#include<string>
using std::string;

class Solution {
public:
    int countCollisions(string directions) {
        
        int result = 0;
        bool s = false; // did i see a stationary wreckage behind
        int r = 0; // how many cars currently moving to the right

        for(char direction : directions) {
            if(direction == 'R') {
                ++r;
                s = false;
            } else if (direction == 'S') {
                if(r > 0) {
                    result += r;
                }
                r = 0;
                s = true;
            } else {
                if(s) {
                    result += 1;
                } else if(r > 0) {
                    result += r + 1;
                    s = true;
                    r = 0;
                }
            }
        } 
        return result;
    }
};