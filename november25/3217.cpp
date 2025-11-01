#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;


//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> s;
        for (int x : nums)
        {
            s.insert(x);
        }

        ListNode *current = head;
        ListNode *prev = nullptr;

        while (current)
        {
            if (s.find(current->val) != s.end())
            {
                deleteNode(head, current, prev);
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }

private:
    void deleteNode(ListNode *&head, ListNode *&current, ListNode *&prev)
    {

        if (head == current)
        {
            ListNode *deleted = head;
            head = head->next;
            current = head;
            prev = nullptr;
            // delete deleted; leetcode having problems with this
        }
        else if (!current->next)
        {
            ListNode *deleted = current;
            prev->next = nullptr;
            current = nullptr;
            delete deleted;
        }
        else
        {
            ListNode *deleted = current;
            prev->next = current->next;
            current = current->next;
            delete deleted;
        }
    }
};