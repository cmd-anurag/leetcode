#include<unordered_map>
#include<vector>
using namespace std;

class FenwickTree {
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1, 0) {}
    void update(int i, int val) {
        for (; i < tree.size(); i += i & -i)
            tree[i] += val;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> pos1;
        for (int i = 0; i < n; ++i)
            pos1[nums1[i]] = i;

        vector<int> rel_pos(n);
        for (int i = 0; i < n; ++i)
            rel_pos[i] = pos1[nums2[i]];

        FenwickTree prefix(n), suffix(n);
        for (int p : rel_pos)
            suffix.update(p + 1, 1);

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            int cur = rel_pos[i];
            suffix.update(cur + 1, -1);
            result += (long long)prefix.query(cur) *
                      (suffix.query(n) - suffix.query(cur));
            prefix.update(cur + 1, 1);
        }
        return result;
    }
};