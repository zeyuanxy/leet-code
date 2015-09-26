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
        ListNode *temp = head;
        int preValue = head->val;
        while(head->next != NULL)
        {
            ListNode *headNext = head->next;
            if(headNext->val == preValue)
                head->next = headNext->next;
            else
            {
                preValue = headNext->val;
                head = head->next;
            }
        }
        return temp;
    }
};