#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>


using namespace std;


// BRUTE FORCE (TIME LIMIT EXCEEDED)

// int findMinDifference(vector<string>& timePoints) {
//     int minTime = 1439;
//     int time1hours;
//     int time2hours;
//     int time1minutes;
//     int time2minutes;
//     int timediff;
//     int diff;

//     for(int i = 0; i < timePoints.size(); ++i) {

//         time1hours = stoi(timePoints[i].substr(0, 2));
//         time1minutes = time1hours*60 + stoi(timePoints[i].substr(3, 2));

//         for(int j = 0; j < timePoints.size(); ++j) {
//             time2hours = stoi(timePoints[j].substr(0, 2));
//             time2minutes = time2hours*60 + stoi(timePoints[j].substr(3, 2));
//             diff = abs(time1minutes - time2minutes);
//             timediff = min(diff, 1440-diff);
//             if(timediff < minTime) {
//                 minTime = timediff;
//             }
//         }
//     }
//     return minTime;
// }

// A better appraoch is to sort the array first.

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> timeMinutes = {};
        for (string time : timePoints) {
            int minutes =
                stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
            timeMinutes.push_back(minutes);
        }
        sort(timeMinutes.begin(), timeMinutes.end());

        int minTime = INT32_MAX;

        for (int i = 1; i < timeMinutes.size(); ++i) {
            if ((timeMinutes[i] - timeMinutes[i - 1]) < minTime)
                minTime = abs(timeMinutes[i] - timeMinutes[i - 1]);
        }

        int firstlastdiff =
            1440 - (timeMinutes[timeMinutes.size() - 1] - timeMinutes[0]);
            cout << minTime << endl;
            cout << firstlastdiff << endl;

        if (minTime < firstlastdiff) {
            return minTime;
        } else {
            return firstlastdiff;
        }
    }
};