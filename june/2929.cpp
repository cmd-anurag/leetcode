class Solution {
public:
    long long countWays(int total) {
        if (total < 0) return 0;
        return 1LL * (total + 2) * (total + 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        long long totalWays = countWays(n);
        totalWays -= 3 * countWays(n - limit - 1);
        totalWays += 3 * countWays(n - 2 * (limit + 1));
        totalWays -= countWays(n - 3 * (limit + 1));
        return totalWays;
    }
};
