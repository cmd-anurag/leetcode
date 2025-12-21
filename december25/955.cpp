#include<vector>
#include<string>
using std::string, std::vector, std::fill, std::min;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs.at(0).size();
        int result = 0;

        // stores min col index at which the ith row was already sorted
        vector<int> isOrdered(rows - 1, -1);

        // stores suggested changes to be made to isOrdered vector
        vector<int> updates(rows - 1, -1);



        for(int col = 0; col < cols; ++col) {
            bool toBeDeleted = false;
            fill(updates.begin(), updates.end(), -1);

            for(int row = 0; row < rows - 1; ++row) {

                if(strs[row][col] < strs[row + 1][col]) {
                    updates[row] = col;
                } 
                else if( strs[row][col] > strs[row + 1][col] ) {
                    if(isOrdered[row] == -1) {
                        toBeDeleted = true;
                        ++result;
                        break;
                    }
                }
            }

            if(toBeDeleted) continue;

            for(int i = 0; i < rows -1; ++i) {
                if(updates[i] == -1) continue;

                if(isOrdered[i] == -1) {
                    isOrdered[i] = updates[i];
                } else {
                    isOrdered[i] = min(isOrdered[i], updates[i]);
                }
            }
        }

        return result;
    }
};