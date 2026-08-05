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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode* slow = head, *fast = head->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next, *prev = nullptr, *list1 = head, *front, *list2;
        while(curr) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        slow->next = NULL;
        list2 = prev;

        while (list1 && list2) {
            ListNode* t1 = list1->next;
            ListNode* t2 = list2->next;

            list1->next = list2;
            list2->next = t1;

            list1 = t1;
            list2 = t2;
        }

        return;
    }
};
