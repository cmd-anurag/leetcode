#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

 bool canArrange(vector<int>& arr, int k) {
    unordered_map<long long int, int> remFreq;
    int remainder;
    for(long long int x : arr) {
            remainder = ((x%k)+k)%k;
            remFreq[remainder]++;
    }
    
    for(auto it = remFreq.begin(); it != remFreq.end(); ++it) {
        if(it->first == 0) {
            if(it->second % 2 != 0) {
                return false;
            }
        }
        else {
            if(it->second != remFreq[k - it->first]) { 
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    cout << canArrange(arr, 5) << endl;
    return 0;
}