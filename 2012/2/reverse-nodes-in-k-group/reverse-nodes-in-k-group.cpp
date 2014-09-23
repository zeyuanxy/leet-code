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
    ListNode *reverseList(ListNode *head, int k) {
        if(head == NULL || head->next == NULL || k == 1)
            return head;
        ListNode *newHead = reverseList(head->next, k - 1);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *guard = new ListNode(0);
        guard->next = head;
        ListNode *p = guard;
        while(p) {
            ListNode *q = p;
            int i = 0;
            while(q->next && i < k) {
                q = q->next;
                ++ i;
            }
            if(i != k)
                break;
            q = q->next;
            ListNode *temp = p->next;
            p->next = reverseList(p->next, k);
            if(temp != NULL)
                temp->next = q; 
            p = temp;
        }
        return guard->next;
    }
};