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
    bool isValidNode(TreeNode *root, int low, int high) {
        if(!root)
            return true;
        return (root->val > low && root->val < high && isValidNode(root->left, low, root->val) && isValidNode(root->right, root->val, high));
    }

    bool isValidBST(TreeNode *root) {
        return isValidNode(root, INT_MIN, INT_MAX);
    }
};