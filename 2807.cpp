#include <iostream>
using namespace std;


struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int calculateGCD(int x, int y) {
    if (y==0) {
        return x;
    }
    return calculateGCD(y, x%y);
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode *current = head;
    ListNode *newnode = NULL;
    while (current->next != NULL) {
        int gcd = calculateGCD(max(current->val, current->next->val), min(current->val, current->next->val));
        newnode = new ListNode(gcd);
        current->next = newnode;
        current = current->next;
    }
    return head;
}

int main() {
    
}