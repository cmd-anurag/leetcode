#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;

        unordered_set<int> inserted;

        vector<int> result;

        for(int i : nums1) {
            set1.insert(i);
        }
        for(int i : nums2) {
            set2.insert(i);
            if(set1.find(i) != set1.end() && inserted.find(i) == inserted.end()) {
                result.push_back(i);
                inserted.insert(i);
            }
        }
        return result;
        
    }

int main()
{
    
    return 0;
}