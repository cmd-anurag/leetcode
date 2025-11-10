#include<vector>
#include<stack>

using std::vector;
using std::stack;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        

        stack<int> st;
        int result = 0;

        for(int x : nums) {
            
            while(!st.empty() && st.top() > x) st.pop(); // monotonic increasing stack

            if(x == 0) continue;

            if(st.empty() || st.top() < x) {
                ++result;
                st.push(x);
            }
        }

        return result;
    }
};