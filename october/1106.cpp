#include<iostream>
#include<stack>
#include<vector>


using namespace std;


bool parseBoolExpr(string expression) {

    stack<char> s;

    for(char c : expression) {
        if(c == 't' || c == 'f') {
            s.push(c);
            continue;
        }

        if(c == '&' || c == '|' || c == '!') {
            s.push(c);
            continue;
        }

        if(c == '(') {
            s.push(c);
            continue;
        }

        if(c == ')') {
            bool hasTrue = false;
            bool hasFalse = false;
            while(s.top() != '(') {
                if(s.top() == 't') hasTrue = true;
                if(s.top() == 'f') hasFalse = true;
                s.pop();
            }
            s.pop();
            char op = s.top();
            s.pop();
            
            if(op == '&') {
                if(hasFalse) {
                    s.push('f');
                }
                else {
                    s.push('t');
                }
            }

            if(op == '|') {
                if(hasTrue) {
                    s.push('t');
                }
                else {
                    s.push('f');
                }
            }

            if(op == '!') {
                if(hasTrue) {
                    s.push('f');
                }
                else {
                    s.push('t');
                }
            }
        }
    }
    
    return s.top() == 't';
}

int main()
{
    string expression = "&(|(f))";
    parseBoolExpr(expression);
    return 0;
}