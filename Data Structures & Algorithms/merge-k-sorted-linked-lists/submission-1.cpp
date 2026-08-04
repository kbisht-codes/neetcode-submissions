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
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* newHead, *temp;
        if(list1->val < list2->val) {
            temp = list1;
            list1 = list1->next;
        }
        else {
            temp = list2;
            list2 = list2->next;
        }
        newHead = temp;
        while(list1 && list2) {
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1)
            temp->next = list1;
        if(list2)
            temp->next = list2;
        return newHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        while(lists.size() > 1) {
            vector<ListNode*> merged;
            for(int i = 0; i < lists.size(); i+= 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
                merged.push_back(merge2Lists(l1, l2));
            }
            lists = merged;
        }
        return lists[0];
    }
};
