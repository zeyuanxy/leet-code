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
    bool isHeightBalanced(TreeNode *root, int &depth)
    {
        if(root == NULL)
        {
            depth = 0;
            return true;
        }
        int leftDepth, rightDepth;
        bool leftBalance = isHeightBalanced(root->left, leftDepth), rightBalance = isHeightBalanced(root->right, rightDepth);
        depth = max(leftDepth, rightDepth) + 1;
        return leftBalance && rightBalance && abs(leftDepth - rightDepth) <= 1;
    }


    bool isBalanced(TreeNode *root) {
        int depth;
        return isHeightBalanced(root, depth);
    }
};