/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *prev = NULL;
        while (head != NULL) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        
        int length = 0;
        ListNode *p = head;
        while (p) {
            p = p->next;
            ++length;
        }
        p = head;
        length /= 2;
        int index = 1;
        while (index < length) {
            p = p->next;
            ++index;
        }
        ListNode* pp = p->next;
        p->next = NULL;
        p = head;
        pp = reverseList(pp);
        while (p && pp) {
            if (p->val != pp->val) {
                return false;
            }
            p = p->next;
            pp = pp->next;
        }
        return true;
    }
};