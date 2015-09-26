/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
  public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
                  ListNode *iter = headA;
                          int lenA = 0;
                                  while (iter) {
                                                ++lenA;
                                                            iter = iter->next;
                                                                    }
                                          iter = headB;
                                                  int lenB = 0;
                                                          while (iter) {
                                                                        ++lenB;
                                                                                    iter = iter->next;
                                                                                            }
                                                                  while (headA && headB) {
                                                                                if (headA->val == headB->val)
                                                                                                  return headA;
                                                                                            if (lenA < lenB) {
                                                                                                              --lenB;
                                                                                                                              headB = headB->next;
                                                                                                                                          } else if (lenA > lenB) {
                                                                                                                                                            --lenA;
                                                                                                                                                                            headA = headA->next;
                                                                                                                                                                                        } else {
                                                                                                                                                                                                          --lenA, --lenB;
                                                                                                                                                                                                                          headA = headA->next;
                                                                                                                                                                                                                                          headB = headB->next;
                                                                                                                                                                                                                                                      }
                                                                                                    }
                                                                          return NULL;
                                                                              }
};
