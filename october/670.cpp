#include<iostream>
#include<vector>
#include<string>

using namespace std;

int maximumSwap(int num) {
    string number = to_string(num);
    int n = number.length();

    vector<int> maxToRight(n);

    int maxNumIdx = n-1;

    for(int i = n-1; i >= 0; --i) {
        
        if(number.at(i) > number.at(maxNumIdx)) {
            maxNumIdx = i;
        }

        maxToRight.at(i) = maxNumIdx;
    }

    for(int i = 0; i < n; ++i) {
        // cout << number.at(i) << " " << number.at(maxToRight.at(i)) << "\n";
        if(number.at(i) < number.at(maxToRight.at(i))) {

            char temp = number.at(i);
            number.at(i) = number.at(maxToRight.at(i));
            number.at(maxToRight.at(i)) = temp;
            return stoi(number);
        }
    }
    return stoi(number);
}

int main()
{
    cout << maximumSwap(9973);
    return 0;
}