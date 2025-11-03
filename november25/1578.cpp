
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int p1 = 0;
        int p2 = 1;

        int result = 0;

        while(p2 < colors.size()) {
            if(colors[p1] == colors[p2]) {
                if(neededTime[p1] <= neededTime[p2]) {
                    result += neededTime[p1];
                    p1 = p2;
                    p2++;
                }
                else {
                    result += neededTime[p2];
                    p2++;
                }
            }
            else {
                p1 = p2;
                p2++;
            }
        }
        return result;
    }
};