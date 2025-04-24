#include <vector>
#include <unordered_set>
#include <unordered_map>
using std::vector;

class Solution
{
public:
    // int countCompleteSubarrays(vector<int> &nums)
    // {
    //     std::unordered_set<int> set;
    //     int n = nums.size();

    //     for (int i : nums)
    //     {
    //         set.insert(i);
    //     }

    //     int k = set.size();
    //     set.clear();

    //     int count = 0;

    //     for (int i = 0; i < n; ++i)
    //     {
    //         for (int j = i; j < n; ++j)
    //         {
    //             for (int k = i; k <= j; ++k)
    //             {
    //                 set.insert(nums[k]);
    //             }
    //             if (set.size() == k)
    //             {
    //                 ++count;
    //             }
    //             set.clear();
    //         }
    //     }
    //     return count;
    // }

    int countCompleteSubarrays(vector<int> &nums)
    {
        std::unordered_map<int, int> map;
        std::unordered_set<int> set;

        for (int x : nums)
        {
            set.insert(x);
        }
        int k = set.size();
        int n = nums.size();
        int i = 0;
        int j = 0;

        int result = 0;

        while (j < n)
        {

            map[nums[j]]++;

            while (map.size() == k)
            {
                result += (n - j);
                map[nums[i]]--;
                if (map[nums[i]] == 0)
                    map.erase(nums[i]);
                ++i;
            }

            ++j;
        }
        return result;
    }
};