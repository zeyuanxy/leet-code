/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
            return NULL;
        
        ListNode *guard = new ListNode(0);
        guard->next = head;
        ListNode *iter = guard;
        while(iter) {
            if(iter->next && iter->next->next && iter->next->val == iter->next->next->val) {
                while(iter->next && iter->next->next && iter->next->val == iter->next->next->val) {
                    iter->next->next = iter->next->next->next;
                }
                iter->next = iter->next->next;
            }
            else
                iter = iter->next;
        }
        return guard->next;
    }
};