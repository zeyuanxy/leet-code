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
    void deleteNode(ListNode* node) {
        if (node == NULL) {
            return;
        }
        ListNode *last_node = NULL;
        while (node->next != NULL) {
            node->val = node->next->val;
            last_node = node;
            node = node->next;
        }
        last_node->next = NULL;
        delete node;
    }
};