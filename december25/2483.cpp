#include<string>
#include<vector>
#include <climits>
using std::vector;
using std::string;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> noToLeft(n+1);
        vector<int> yesToRight(n+1);

        int noCount = 0;
        for(int i = 0; i <= n; ++i) {
            noToLeft[i] = noCount;
            if(i < n && customers[i] == 'N') ++noCount;
        }
        int yesCount = 0;
        for(int i = n; i >= 0; --i) {
            yesToRight[i] = yesCount;
            if(i < n && customers[i] == 'Y') ++yesCount;
        }


        int result = 0;
        int minPenalty = INT_MAX;

        for(int i = 0; i <= n; ++i) {

            int penalty = noToLeft[i] + yesToRight[i];
            if(i < n && customers[i] == 'Y') penalty++;
            
            if(penalty < minPenalty) {
                result = i;
                minPenalty = penalty;
            }
        }

        return result;
    }
};