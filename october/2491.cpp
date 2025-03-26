#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

long long dividePlayers(vector<int>& skill) {

    long long int chemistry = 0;
    sort(skill.begin(), skill.end());
    int left = 0;
    int right = skill.size() - 1;
    int targetSkill = skill[left]+skill[right];
    bool flag = true;
    while(left < right) {
        if(skill[left]+skill[right] == targetSkill) {
            chemistry += skill[left]*skill[right];
            ++left;
            --right;
        }
        else {
            flag = false;
            break;
        }
    }
    if(flag) {
        return chemistry;
    }
    else {
        return -1;
    }
}

int main() {

}