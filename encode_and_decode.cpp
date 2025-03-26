//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        char delimeter = '→';
        string encoded = "";
        for(string str : s) {
            encoded += str;
            encoded += delimeter;
        }
        return encoded;
    }

    vector<string> decode(string& s) {
        // code here
        char delimeter = '→';
        vector<string> result;
        string word = "";
        for(char c : s) {
            if(c == delimeter) {
                result.push_back(word);
                word = "";
            }
            else {
                word += c;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // To ignore the newline after the number of test cases

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        string word;
        vector<string> s;

        while (ss >> word) {
            s.push_back(word);
        }

        Solution obj;
        string encodedString = obj.encode(s);
        vector<string> decodedStrings = obj.decode(encodedString);

        for (string x : decodedStrings) {
            cout << x << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends