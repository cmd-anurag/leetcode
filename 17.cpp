#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_map<char, vector<char>> map;

    void recur(vector<string> &result, int i, string digits, string sub)
    {
        if (i == digits.length())
        {
            result.push_back(sub);
            return;
        }
        for (auto letter : map[digits[i]])
        {
            recur(result, i + 1, digits, sub + letter);
        }
    }

    vector<string> letterCombinations(string digits)
    {

        map['2'] = {'a', 'b', 'c'};
        map['3'] = {'d', 'e', 'f'};
        map['4'] = {'g', 'h', 'i'};
        map['5'] = {'j', 'k', 'l'};
        map['6'] = {'m', 'n', 'o'};
        map['7'] = {'p', 'q', 'r', 's'};
        map['8'] = {'t', 'u', 'v'};
        map['9'] = {'w', 'x', 'y', 'z'};

        vector<string> result = {};

        if (digits.empty())
            return result;

        int i = 0;
        recur(result, i, digits, "");
        return result;
    }
};