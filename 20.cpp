#include<stack>
#include<iostream>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if(c == ')' || c == '}' || c == ']'){
            if(st.empty() || c == ')' && st.top() != '(') return false;
            else if(st.empty() || c == '}' && st.top() != '{') return false;
            else if(st.empty() || c == ']' && st.top() != '[') return false;
            else {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main() {
    string s = "]";
    cout << isValid(s);
}