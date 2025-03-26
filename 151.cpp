#include<stack>
#include<string>
#include<iostream>

using namespace std;

string reverseWords(string s) {
    stack<string> wordStack;
    string word = "";
    for(char c : s) {
        if(c == ' ' && word.empty()) {
            continue;
        }
        else if(c == ' ' && !word.empty()) {
            wordStack.push(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    if(word!="") {
        wordStack.push(word);
    }
    string output = "";
    output+=wordStack.top();
    wordStack.pop();
    while (!wordStack.empty())
    {
        output += " ";
        output += wordStack.top();
        wordStack.pop();
    }
    return output;
}


int main()
{
    string s = "  one ";
    
    string output = reverseWords(s);
    cout << output.length();
    return 0;
}