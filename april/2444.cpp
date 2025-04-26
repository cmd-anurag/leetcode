#include <vector>
using std::vector;
using ll = long long;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int brainCellCount = nums.size();

        ll finalBoss = 0;

        int topDog = -1;
        int underDog = -1;
        int partyPooper = -1;

        // haha this makes my code super unreadable but fun xD;

        for(int i = 0; i < brainCellCount; ++i) {
            if(nums[i] < minK || nums[i] > maxK) 
                partyPooper = i;

            if(nums[i] == minK)
                underDog = i;
            if(nums[i] == maxK)
                topDog = i;

            int realGangster = std::min(topDog, underDog);
            int temp = realGangster - partyPooper;

            finalBoss += temp > 0? temp : 0;
        }

        return finalBoss;
    }
};