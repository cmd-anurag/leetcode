#include<iostream>
#include<vector>
#include<queue>


using namespace std;


int main()
{
    vector<vector<int>> array = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
    
    int right = INT_MIN;

    for(int i = 0; i < array.size(); ++i) {
        minHeap.push({array[i][0], i, 0});
        right = max(right, array[i][0]);
    }

    int left = get<0>(minHeap.top());

    vector<int> result = {left, right};
    while(!minHeap.empty()) {

        auto [minElement, minlistIndex, minelementIndex] = minHeap.top();
        minHeap.pop();
        left = minElement;
        if(right - left < result[1] - result[0]) {
            result[0] = left;
            result[1] = right;
        }

        ++minelementIndex;

        if(minelementIndex >= array[minlistIndex].size()) {
            break;
        }

        minHeap.push({array[minlistIndex][minelementIndex], minlistIndex, minelementIndex});
        right = max(right, array[minlistIndex][minelementIndex]);
        

    }

    cout << result[0] << " " << result[1];

    return 0;
}