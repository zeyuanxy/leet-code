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
    bool hasCycle(ListNode *head) {
        ListNode *pFast = head, *pSlow = head;
        do
        {
            if(pFast != NULL)
                pFast = pFast->next;
            if(pFast != NULL)
                pFast = pFast->next;
            if(pFast == NULL)
                return false;
            pSlow = pSlow->next;
        }while(pFast != pSlow);
        return true;
    }
};