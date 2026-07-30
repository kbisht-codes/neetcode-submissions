/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode *temp = head, *left = NULL, *right;
        while(temp && temp->next) {
            right = temp->next;
            temp->next = left;
            left = temp;
            temp = right;
        }
        temp->next = left;
        return temp;
    }
};
