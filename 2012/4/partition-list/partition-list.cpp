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
    ListNode *partition(ListNode *head, int x) {
        ListNode lowGuard(0), highGuard(0);
        ListNode *low = &lowGuard, *high = &highGuard;
        while(head) {
            if(head->val < x) {
                low->next = head;
                low = head;
            }
            else {
                high->next = head;
                high = head;
            }
            head = head->next;
        }
        low->next = highGuard.next;
        high->next = NULL;
        return lowGuard.next;
    }
};