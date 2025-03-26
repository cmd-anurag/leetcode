#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// BRUTE FORCE

int smallestChair(vector<vector<int>>& times, int targetFriend) {
    vector<int> targetFriendTime = times[targetFriend];
    std::sort(times.begin(), times.end());

    int n = times.size();
    vector<int> chairs(n);

    for(vector<int> time : times) {
        for(int i = 0; i<n; ++i) {
            if(chairs[i] <= time[0]) {
                chairs[i] = time[1];
                if(time == targetFriendTime) {
                    return i;
                }
                break;
            }
        }
    }
    return 0;
}


int main()
{
    
    return 0;
}