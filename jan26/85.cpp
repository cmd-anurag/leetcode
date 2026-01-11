#include<vector>
#include<stack>
using std::vector, std::stack, std::max;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 0;

        vector<int> heights(m);
        for(int row = 0; row < n; ++row) {

            for(int col = 0; col < m; ++col) {

                if(matrix[row][col] == '1') {
                    heights[col] += 1;
                } else {
                    heights[col] = 0;
                }
            }

            vector<int> widths = calculateWidths(heights);
            
            for(int col = 0; col < m; ++col) {
                int currentArea = heights[col] * widths[col];
                result = max(result, currentArea); 
            }
        }
        return result;

    }
    vector<int> calculateWidths(vector<int> &heights) {
        int m = heights.size();
        vector<int> widths(m);

        vector<int> nextSmallerToRight(m);
        vector<int> nextSmallerToLeft(m);

        stack<int> s; // stores the index of the next smaller not the smaller element itself
        for(int i = m - 1; i >= 0; --i) {
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();

            if(s.empty()) {
                nextSmallerToRight[i] = -1;
                s.push(i);
            } else {
                nextSmallerToRight[i] = s.top();
                s.push(i);
            }
        }
        
        while(!s.empty()) s.pop();

        for(int i = 0; i < m; ++i) {
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();

            if(s.empty()) {
                nextSmallerToLeft[i] = -1;
                s.push(i);
            } else {
                nextSmallerToLeft[i] = s.top();
                s.push(i);
            }
        }

        for(int i = 0; i < m; ++i) {
            
            int left = nextSmallerToLeft[i];
            int right = nextSmallerToRight[i];

            if(left != -1 && right != -1) {
                widths[i] = right - left - 1;
            }
            else if(left == -1 && right == -1) {
                widths[i] = m;
            }
            else if(left == -1) {
                widths[i] = right;
            } else if(right == -1) {
                widths[i] = m - left - 1;
            }
        }
        return widths;
    }
};