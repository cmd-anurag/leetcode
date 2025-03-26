#include<iostream>
#include<vector>

using namespace std;

void reverse(vector<int>& row) {
    int start = 0;
    int end = row.size()-1;

    while(start < end) {
        swap(row.at(start), row.at(end));
        ++start;
        --end;
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void rotate(vector<vector<int>>& matrix) {

    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = i+1; j < matrix.at(0).size(); ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i<matrix.size(); ++i) {
        reverse(matrix[i]);
    }
}

void display(vector<vector<int>> matrix) {
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix.at(0).size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    display(matrix);
    rotate(matrix);
    cout << endl;
    display(matrix);
    return 0;
}