/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode *newHead = NULL, *iter = head;
        while(iter) {
            RandomListNode *next = iter->next;
            iter->next = new RandomListNode(iter->label);
            iter->next->next = next;
            if(newHead == NULL)
                newHead = iter->next;
            iter = next;
        }
        iter = head;
        while(iter) {
            if(iter->random)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        iter = head;
        while(iter) {
            RandomListNode *next = iter->next;
            iter->next = next->next;
            if(iter->next)
                next->next = next->next->next;
            iter = iter->next;
        }
        return newHead;
    }
};