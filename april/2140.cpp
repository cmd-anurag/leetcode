#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_map<int, long long int> map;

    long long int recurse(long long int i, vector<vector<int>> &questions)
    {

        if (i >= questions.size())
        {
            return 0;
        }

        if (map.find(i) != map.end())
        {
            return map[i];
        }

        long long int points = questions[i][0];

        long long int p1 = recurse(i + 1, questions);
        long long int p2 = points + recurse(i + 1 + questions[i][1], questions);

        long long int result = max(p1, p2);
        map[i] = result;

        return result;
    }

    long long mostPoints(vector<vector<int>> &questions)
    {

        long long int i = 0;
        return recurse(i, questions);
    }
};