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
    ListNode *reverseList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return;
            
        ListNode *slow = head, *fast = head;
        while(fast != NULL) {
            fast = fast->next;
            if(fast)
                fast = fast->next;
            if(fast == NULL)
                break;
            slow = slow->next;
        }
        ListNode *head2 = reverseList(slow->next);
        slow->next = NULL;
        while(head != NULL && head2 != NULL) {
            ListNode *next = head->next;
            head->next = head2;
            head = next;
            next = head2->next;
            head2->next = head;
            head2 = next;
        }
    }
};