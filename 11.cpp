#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;


int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = INT32_MIN;
    int currentArea;
    while (left < right)
    {
        currentArea = (min(height[left], height[right]))*(right-left);
        if(currentArea > maxArea) {
            maxArea = currentArea;
        }
        height[left] < height[right] ? left++ : right--;
    }
    return maxArea;
}

int main() {
    vector<int> height = {1,1};
    cout << maxArea(height);
}