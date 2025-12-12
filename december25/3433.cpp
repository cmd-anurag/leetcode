#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using std::string, std::unordered_map, std::vector, std::sort, std::to_string;

bool compare(const vector<string>& a, const vector<string> &b) {
    int t1 = stoi(a[1]);
    int t2 = stoi(b[1]);
    if(t1 == t2) {
        string type1 = a[0];
        string type2 = b[0];
        return type1 > type2;
    } else {
        return t1 < t2;
    }
}

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers);
        int allCount = 0;
        unordered_map<string, int> offline; // user id -> when they will be online

        sort(events.begin(), events.end(), compare);

        // for(auto &event : events) {
        //     cout << event[0] << " " << event[1] << " " << event[2] << '\n';
        // }
        for(auto &event : events) {
            string type = event[0];
            int timeStamp = stoi(event[1]);

            if(type == "OFFLINE") {
                string id = event[2];
                offline[id] = timeStamp + 60;
            } else {

                string mentions_string = event[2];
                if(mentions_string == "ALL") {
                    allCount++;
                } else if(mentions_string == "HERE") {
                    for(int i = 0; i < numberOfUsers; ++i) {
                        string sid = to_string(i);
                        int onTimestamp = offline[sid];
                        if(onTimestamp == 0) {
                            mentions[i]++;
                        } else if(onTimestamp <= timeStamp) {
                            mentions[i]++;
                            offline.erase(sid);
                        }
                    }
                } else {
                    vector<int> ids = getIDS(mentions_string);
                    for(int id : ids) {
                        mentions[id]++;
                    }
                }
            }
        }
        // vector<int> ids = getIDS("id1 id0");
        // for(int i : ids) {
        //     cout << i << " ";
        // }

        for(int i = 0; i < numberOfUsers; ++i) {
            mentions[i] += allCount;
        }
        return mentions;
    }
    vector<int> getIDS(string mentions_string) {
        vector<int> result;
        vector<string> words; 
        string word = "";
        for(char c : mentions_string) {
            if(c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word);
        for(auto &word : words) {
            result.push_back(stoi(word.substr(2)));
        }
        return result;
    }
};