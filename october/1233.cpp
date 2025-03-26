#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


vector<string> removeSubfolders(vector<string>& folder) {
    unordered_set<string> set(folder.begin(), folder.end());

    vector<string> res;

    for(string f : folder) {
        bool flag = false;
        string prefix = f;
        while(!prefix.empty()) {
            int position = prefix.find_last_of('/');
            if(position == string::npos) break;

            prefix = prefix.substr(0, position);

            if(set.count(prefix)) {
                flag = true;
                break;
            }

        }

        if(!flag) {
            res.push_back(f);
        }
    }

    return res;

}

int main()
{
    
    return 0;
}
