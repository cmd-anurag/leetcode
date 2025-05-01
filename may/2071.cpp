
// what a fitting problem on labour day 😆

#include<vector>
#include<algorithm>
#include<set>

using std::vector;

class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        int m = tasks.size();
        int n = workers.size();

        int l = 0;
        int r = std::min(m, n);

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), std::greater<int>());  

        int result = 0;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canYouDoIt(tasks, workers, strength, pills, mid)) {
                result = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return result;


    }
private:
    bool canYouDoIt(vector<int> &tasks, vector<int> &workers, int strength, int pills, int x) {
        int pillsUsed = 0;

        // choose x number of strongest workers.
        std::multiset<int> set(std::begin(workers), std::begin(workers) + x);

        // choose x number of easiest tasks
        for(int i = x-1; i >= 0; --i) {
            // iterate from toughest to easiest tasks giving the tougher tasks to stronger workers
            int required = tasks[i];

            auto strongestIt = std::prev(set.end());

            if(*strongestIt >= required) { // can the worker do the task.
                set.erase(strongestIt);
            } 
            else if(pillsUsed >= pills) { // no pills are left
                return false;
            }
            else { // pills can be used;
                // the pill must be used on the weakest worker capable of doing the task after getting the pill.

                auto weakestIt = set.lower_bound(required - strength); // find the weakest worker having the strength to do the task with the pill.
                if(weakestIt == set.end()) { // no such worker exists
                    return false;
                }
                // worker can do the task with pill;
                set.erase(weakestIt);
                ++pillsUsed;
            }
        }
        return true;
    }
};


// TIME - O(m log m + n log n +min(m,n)∗ log(min(m,n)))
// SPACE - O(m+n);