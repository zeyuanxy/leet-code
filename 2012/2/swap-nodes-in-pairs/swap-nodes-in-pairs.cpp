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
    ListNode *swapPairs(ListNode *head) {
        ListNode *iter = head, *preIter = NULL;
        while(iter != NULL && iter->next != NULL)
        {
            ListNode *nextIter = iter->next;
            if(preIter != NULL)
                preIter->next = nextIter;
            preIter = iter;
            if(iter == head)
                head = iter->next;
            iter->next = nextIter->next;
            nextIter->next = iter;
            iter = iter->next;
        }
        return head;
    }
};