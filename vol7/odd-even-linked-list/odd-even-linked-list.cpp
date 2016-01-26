/* 
* @Author: Zeyuan Shang
* @Date:   2016-01-26 22:59:53
* @Last Modified by:   Zeyuan Shang
* @Last Modified time: 2016-01-26 23:00:02
*/

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *odd = head, *even = head->next;
        ListNode *oddHead = head, *evenHead = head->next;
        head = head->next->next;
        bool isOdd = true;
        while (head) {
            if (isOdd) {
                odd->next = head;
                odd = head;
            } else {
                even->next = head;
                even = head;
            }
            isOdd = !isOdd;
            head = head->next;
        }
        odd->next = evenHead;
        even->next = NULL;
        return oddHead;
    }
};