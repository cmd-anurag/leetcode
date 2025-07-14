#include<cmath>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* current = head;

        int length = 0;
        while(current) {
            ++length;
            current = current->next;
        }

        int output = 0;
        current = head;

        while(current) {
            output += current->val * (1 << length - 1);
            current = current->next;
            --length;
        }

        return output;
    }
};