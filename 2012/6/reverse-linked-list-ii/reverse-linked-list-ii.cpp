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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL)
            return NULL;
        ListNode *lGuard = NULL, *rGuard = NULL;
        ListNode *iter = head, *prev = NULL, *curr = NULL, *temp = NULL;
        for(int i = 1; i <= n; ++ i) {
            if(i == m - 1)
                lGuard = iter;
            if(i == m)
                curr = iter;
            if(i == n)
                rGuard = iter->next;
            iter = iter->next;
        }
        
        temp = curr;
        prev = curr;
        curr = curr->next;
        for(int i = m + 1; i <= n; ++ i) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        temp->next = rGuard;
        if(lGuard) {
            lGuard->next = prev;
        }
        else
            head = prev;
        return head;
    }
};