#include<vector>
#include<string>
using std::vector, std::string;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int totalCols = strs.at(0).size();
        int totalRows = strs.size();

        for(int col = 0; col < totalCols; ++col) {
            char smallest = strs[0][col];

            for(int row = 1; row < totalRows; ++row) {
                if(strs[row][col] < smallest) {
                    ++count;
                    break;
                } else {
                    smallest = strs[row][col];
                }
            }
        }

        return count;
    }
};