#include<bits/stdc++.h>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int findLength(ListNode *head) {
        int length = 0;
        ListNode *current = head;
        while (current != NULL)
        {
            ++length;
            current = current->next;
        }
        return length;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        ListNode* current = head;
        if(head!=NULL) {
            result.push_back(head);
        }
        int count = 1;
        int N = findLength(head);
        int partsFormed = 1;
        int end;
        while(current != NULL) {
            if(partsFormed <= N%k) {
                end = (N/k)+1;
            }
            else {
                end = N/k;
            }
            if(count == end) {
                ListNode* temp = current->next;
                current->next = NULL;
                if(temp!=NULL) {
                    result.push_back(temp);
                }
                current = temp;
                count=1;
                partsFormed++;
                continue;
            }
            ++count;
            current = current->next;
        }
        while(N<k) {
            result.push_back(NULL);
            N++;
        }
        return result;
    }
};