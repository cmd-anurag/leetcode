#include <vector>
#include <string>
#include <iostream>
using std::string;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.length();

        std::vector<int> leftNearestRight(n); // nearest domino falling toward right on the left of each i
        std::vector<int> rightNearestLeft(n); // nearest domino falling toward left on the right of each i

        for(int i = 0; i < n; ++i) {

            if(dominoes[i] == 'R') {
                leftNearestRight[i] = i;
            }
            else if(dominoes[i] == 'L') {
                leftNearestRight[i] = -1;
            }
            else {
                if(i == 0) {
                    leftNearestRight[i] = -1;
                }
                else {
                    leftNearestRight[i] = leftNearestRight[i-1];
                }
            }
        }

        for(int i = n-1; i >= 0; --i) {
            if(dominoes[i] == 'R') {
                rightNearestLeft[i] = -1;
            }
            else if(dominoes[i] == 'L') {
                rightNearestLeft[i] = i;
            }
            else {
                if(i == n-1) {
                    rightNearestLeft[i] = -1;
                }
                else {
                    rightNearestLeft[i] = rightNearestLeft[i+1];
                }
            }
        }

        // for(int i : leftNearestRight) {
        //     std::cout << i << " ";
        // }
        // std::cout << '\n';

        // for(int i : rightNearestLeft) {
        //     std::cout << i << " ";
        // }
        // std::cout << '\n';

        string result;
        result.reserve(n);

        for(int i = 0; i < n; ++i) {
            if(leftNearestRight[i] != -1 && rightNearestLeft[i] == -1) {
                result.push_back('R');
            }
            else if(leftNearestRight[i] == -1 && rightNearestLeft[i] != -1) {
                result.push_back('L');
            }
            else if(leftNearestRight[i] == -1 && rightNearestLeft[i] == -1) {
                result.push_back('.');
            }
            else {
                int leftDistance = abs(i - leftNearestRight[i]);
                int rightDistance = abs(i - rightNearestLeft[i]);

                if(leftDistance == rightDistance) {
                    result.push_back('.');
                }
                else if(leftDistance < rightDistance) {
                    result.push_back('R');
                }
                else {
                    result.push_back('L');
                }
            }

        }
        
        return result;
        // damn so many if else
    }
};



int main() {
    Solution s;
    std::cout << s.pushDominoes(".L.R...LR..L..");
}