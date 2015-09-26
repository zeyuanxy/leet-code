/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Compare {
public:
    bool operator() (ListNode *a, ListNode* b ){
        return a->val >= b->val;
    }
};
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
         priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
         for(auto & node : lists)
            if(node != NULL)
                pq.push(node);
        ListNode *guard = new ListNode(0), *iter = guard;
        while(!pq.empty()) {
            ListNode *temp = pq.top();
            pq.pop();
            if(temp->next != NULL)
                pq.push(temp->next);
            iter->next = temp;
            iter = temp;
        }
        return guard->next;
    }
};