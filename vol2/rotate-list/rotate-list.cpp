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
    ListNode *rotateRight(ListNode *head, int k) {
        if(k == 0 || head == NULL)
            return head;
            
        int n = 0;
        ListNode *iter = head, *back = NULL;
        while(iter) {
            if(iter->next == NULL)
                back = iter;
            n ++;
            iter = iter->next;
        }
        k %= n;
        if(k == 0)
            return head;
        iter = head;
        int i = 0; 
        while(iter) {
            i ++;
            if(i == (n - k))
                break;
            iter = iter->next;
        }
        ListNode *next = iter->next;
        iter->next = NULL;
        back->next = head;
        return next;
    }
};