/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *convert2BST(ListNode *&head, int start, int end) {
        if(start > end) 
            return NULL;
        int mid = (start + end) / 2;
        TreeNode *left = convert2BST(head, start, mid - 1);
        TreeNode *node = new TreeNode(head->val);
        head = head->next;
        TreeNode *right = convert2BST(head, mid + 1, end);
        node->left = left;
        node->right = right;
        return node;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        ListNode *iter = head;
        while(iter) {
            n ++;
            iter = iter->next;
        }
        
        return convert2BST(head, 0, n - 1);
    }
};