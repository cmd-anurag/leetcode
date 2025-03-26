#include<bits/stdc++.h>

using namespace std;

vector<string> stringToWords(string line) {
    vector<string> output;
    string word = "";
    for(char c : line) {
        if(c == ' ') {
            output.push_back(word);
            word = "";
        }
        else {
            word.push_back(c);
        }
    }
    output.push_back(word);
    return output;
}

vector<string> uncommonFromSentences(string s1, string s2) {

    vector<string> result;
    string combined = s1+s2;
    vector<string> words = stringToWords(combined);
    unordered_map<string, int> hash;

    for(string word : words) {
        if(hash.count(word) > 0) {
            hash[word]++;
        }
        else {
            hash[word] = 1;
        }
    }

    for(string word : words) {
        if(hash.count(word) == 1) {
            result.push_back(word);
        }
    }   
    
    return result;
}

int main() {

	
    
}