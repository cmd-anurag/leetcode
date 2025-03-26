#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string lcs = "";
        string lcp = "";

        int l1 = sentence1.length();
        int l2 = sentence2.length();

        

        bool nextspace = true;
        bool prevspace = true;

        string largersentence = l1 > l2 ? sentence1 : sentence2;

        for (int i = 0; i < min(l1, l2); ++i) {

            if (largersentence[i + 1] == ' ') {
                nextspace = true;
            } else {
                nextspace = false;
            }

            if (sentence1[i] == sentence2[i]) {
                lcp += sentence1[i];
            } else {
                break;
            }
        }

        if(l1 == l2 || lcp.empty()) nextspace = true;

        int ps1 = l1 - 1;
        int ps2 = l2 - 1;

        while (min(ps1, ps2) >= 0 && sentence1[ps1] == sentence2[ps2]) {
            lcs += sentence1[ps1];
            --ps1;
            --ps2;
        }
        if(max(ps1, ps2) >= 0 && largersentence.at(max(ps1,ps2)) != ' ') prevspace = false;
        reverse(lcs.begin(), lcs.end());


        cout << lcp << '\n';
        cout << lcs << '\n';
        cout << nextspace;
        
        if (((lcp == sentence1 || lcp == sentence2) && nextspace) || (lcs == sentence1 || lcs == sentence2)&&prevspace) {
            return true;
        }
        

        if (!lcp.empty() && !lcs.empty() && lcp.back() == ' ' &&
            lcs.front() == ' ') {
            lcp.pop_back();

            return (lcp + lcs == sentence1 || lcp + lcs == sentence2);
        }
        
        else {
            return false;
        }
    }
    };


int main() {

    
}