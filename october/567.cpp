#include<iostream>
#include<string>



using namespace std;



bool compareArrays(const int arr1[26], const int arr2[26]) {
    for (int i = 0; i < 26; ++i) {
        if (arr1[i] != arr2[i]) {
            return false;  
        }
    }
    return true;  
}

bool checkInclusion(string s1, string s2) {

    int s1freq[26] = {};
    int s2freq[26] = {};

    for(char c : s1) {
        ++s1freq[c-97];
    }

    int left = 0;
    int right = 0;

    while(right < s1.length()) {
        ++s2freq[s2[right-97]];
        ++right;
    }
    
    if(compareArrays(s1freq, s2freq)) return true;
    
    for(int i = s1.length(); i < s2.length(); ++i) {
        if(compareArrays(s1freq, s2freq)) return true;
        s2freq[s2[i] - 97]++;

        
        s2freq[s2[i - s1.length()] - 97]--;

        
        if (compareArrays(s1freq, s2freq)) return true;
        
    }
    
    return false;
}

int main()
{
    cout << checkInclusion("hello", "ooolleooolleh");
    return 0;
}