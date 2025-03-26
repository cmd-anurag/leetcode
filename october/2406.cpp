#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int minGroups(vector<vector<int>>& intervals) {

    vector<int> startIntervals(intervals.size());
    vector<int> endIntervals(intervals.size());

    for(int i = 0; i < intervals.size(); ++i) {
        startIntervals[i] = intervals[i][0];
        endIntervals[i] = intervals[i][1];
    }

    sort(startIntervals.begin(), startIntervals.end());
    sort(endIntervals.begin(), endIntervals.end());

    int i = 0;
    int j = 0;
    
    int result = 0;
    int groups = 0;

    while(i < startIntervals.size()) {
        if(startIntervals[i] <= endIntervals[j]) {
            ++groups;
            ++i;
        }
        else {
            --groups;
            ++j;
        }
        result = groups > result? groups : result;
    }
    return result;
}



int main()
{
    
    return 0;
}