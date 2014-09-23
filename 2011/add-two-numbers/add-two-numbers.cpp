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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL || l2 == NULL)
            return NULL;
        ListNode *head = new ListNode(0);
        ListNode *iter = head;
        while(true) {
            iter->next = new ListNode(0);
            if(l1 != NULL && l2 != NULL)
            {
                iter->next->val = (iter->val + l1->val + l2->val) / 10;
                iter->val = (iter->val + l1->val + l2->val) % 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 == NULL) {
                iter->next->val = (iter->val + l2->val) / 10;
                iter->val = (iter->val + l2->val) % 10;
                l2 = l2->next;
            }
            else if(l2 == NULL) {
                iter->next->val = (iter->val + l1->val) / 10;
                iter->val = (iter->val + l1->val) % 10;
                l1 = l1->next;
            }
            if(l1 || l2)
                iter = iter->next;
            else {
                if(iter->next->val == 0) {
                    delete iter->next;
                    iter->next = NULL;
                }
                break;
            }
        }
        return head;
    }
};