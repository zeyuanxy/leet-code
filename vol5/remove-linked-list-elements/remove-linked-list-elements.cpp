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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }
        while (head != NULL && head->val == val) {
            head = head->next;
        }
        if (head == NULL) {
            return NULL;
        }
        ListNode* prev = head;
        ListNode* node = head->next;
        while (node != NULL) {
            if (node->val == val) {
                prev->next = node->next;
            } else {
                prev = node;
            }
            node = node->next;    
        }
        return head;
    }
};