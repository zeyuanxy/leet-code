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
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
            
        int i = 0;
        ListNode *p = head;
        while(p) {
            ++ i;
            p = p->next;
        }
        ListNode *q = head, *l = NULL;
        for(int j = 0; j < i / 2 && q; ++ j) {
            if(j == i / 2 - 1)
                l = q;
            q = q->next;
        }
        if(l)
            l->next = NULL;
        p = sortList(head);
        q = sortList(q);
        ListNode *ret = NULL, *iter = NULL;
        while(p && q) {
            if(p->val <= q->val) {
                if(ret == NULL)
                    ret = iter = p;
                else {
                    iter->next = p;
                    iter = iter->next;
                }
                p = p->next;
            }
            else {
                if(ret == NULL)
                    ret = iter = q;
                else {
                    iter->next = q;
                    iter = iter->next;
                }
                q = q->next;
            }
        }
        if(p)
            iter->next = p;
        if(q)
            iter->next = q;
        return ret;
    }
};