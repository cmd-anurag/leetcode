#include<set>
#include<unordered_map>
#include<vector>
using std::pair, std::set, std::vector, std::unordered_map;

typedef long long ll;


class Solution {
public:
    ll sum = 0;
    set<pair<int, int>> mainSet;
    set<pair<int, int>> secondarySet;

    void insertInSet(const pair<int, int>& p, int x) {
        if(mainSet.size() < x || p > *mainSet.begin()) {
            sum += (long long)p.first * p.second;
            mainSet.insert(p);

            if(mainSet.size() > x) {
                auto remove = *mainSet.begin();
                sum -= 1LL * remove.first * remove.second;
                mainSet.erase(remove);
                secondarySet.insert(remove);
            }
        }
        else {
            secondarySet.insert(p);
        }
    }

    void removeFromSet(const pair<int, int>& p) {
        if(mainSet.find(p) != mainSet.end()) {
            sum -= 1LL * p.first * p.second;
            mainSet.erase(p);
            if(!secondarySet.empty()) {
                auto remove = *secondarySet.rbegin();
                secondarySet.erase(remove);
                mainSet.insert(remove);
                sum += 1LL * remove.first * remove.second;
            }
        }
        else {
            secondarySet.erase(p);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<ll> result;
        sum = 0;
        unordered_map<int, int> map;

        int i = 0;
        int j = 0;
        while(j < n)
        {
            if(map.find(nums[j]) != map.end()) {
                removeFromSet({map[nums[j]], nums[j]});
            }

            map[nums[j]]++;

            insertInSet({map[nums[j]], nums[j]}, x);

            if(j - i + 1 == k) {
                result.push_back(sum);
                removeFromSet({map[nums[i]], nums[i]});

                map[nums[i]]--;
                if(map[nums[i]] == 0) {
                    map.erase(nums[i]);
                } else {
                    insertInSet({map[nums[i]], nums[i]}, x);
                }
                ++i;
            }
            ++j;
        }
        return result;
    }
};