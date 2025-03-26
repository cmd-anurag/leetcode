#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    
    if(!arr.size()) return arr;
    vector<int> copy = arr;
    std::sort(copy.begin(), copy.end());

    unordered_map<int, int> rankMap;
    int rank = 1;
    rankMap[copy[0]] = rank;
    rank++;
    int lastInsert = copy[0];

    for(int i = 1; i < copy.size(); ++i) {
        if(lastInsert == copy[i]) continue;
        rankMap[copy[i]] = rank;
        ++rank;
        lastInsert = copy[i];
    }
    for(int i = 0; i < arr.size(); ++i) {
        arr[i] = rankMap[arr[i]];
    }
    return arr;
}

int main() {
    
}
