#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

unordered_map<int, int> arrayToMap(vector<int> &nums) {
    unordered_map<int, int> hash;
    for(int i : nums) {
        hash[i] = i;
    }
    return hash;
}
void displayLL(ListNode *head) {
    ListNode *temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}
ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_map<int, int> hash = arrayToMap(nums);
    ListNode* currentNode = head;
    int count = 0;
    while (currentNode!=NULL && currentNode->next != NULL)
    {
        count++;
        if(hash.count(head->val) > 0) {
            ListNode* deleteNode = head;
            head = head->next;
            currentNode = head;
            delete deleteNode;
            continue;
        }
        else if(hash.count(currentNode->next->val) > 0) {
            
            ListNode* deleteNode = currentNode->next;
            currentNode->next = currentNode->next->next;
            delete deleteNode;
            continue;
        }
        else {
            currentNode = currentNode->next;
        }
    }
    return head;
}


int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    unordered_map<int, int> hash = arrayToMap(nums);
    cout << hash[4];
}