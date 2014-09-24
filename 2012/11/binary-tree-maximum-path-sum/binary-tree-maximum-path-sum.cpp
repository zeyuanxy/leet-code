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
private:
    int ans;
public:
    int getSum(TreeNode *root) {
        if(root == NULL)
            return 0;
        
        int value = root->val, lmax = 0, rmax = 0;
        if(root->left)
            lmax = max(0, getSum(root->left));
        if(root->right)
            rmax = max(0, getSum(root->right));
        value += lmax + rmax;
        
        ans = max(ans, value);
        return max(max(root->val, root->val + lmax), root->val + rmax);
    }
    int maxPathSum(TreeNode *root) {
        if(root == NULL)
            return 0;
        ans = -INT_MAX;
        getSum(root);
        return ans;
    }
};