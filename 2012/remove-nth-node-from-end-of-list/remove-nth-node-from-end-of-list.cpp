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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(n == 0)
            return head;
        ListNode *temp = head, *iter = head;
        for(int i = 0; i < n; ++ i)
            iter = iter->next;
        if(iter == NULL)
        {
            head = head->next;
            return head;
        }
        while(iter->next != NULL)
        {
            iter = iter->next;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};