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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL)
            return head;
        ListNode *next = head, *tempNext;
        while(next->next != NULL)
        {
            tempNext = next->next->next;
            if(next->next->val <= head->val)
            {
                next->next->next = head;
                head = next->next;
                next->next = tempNext;
            }
            else
            {
                ListNode *temp = head;
                while(temp != next && temp->next->val < next->next->val)
                    temp = temp->next;
                if(temp == next)
                    next = next->next;
                else
                {
                    next->next->next = temp->next;
                    temp->next = next->next;
                    next->next = tempNext;
                }
            }
        }
        return head;
    }
};