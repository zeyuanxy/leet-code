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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        vector<TreeNode*> stack;
        while(root || stack.size() > 0)
        {
            while(root)
            {
                stack.push_back(root);
                root = root->left;
            }
            root = stack[stack.size() - 1];
            stack.pop_back();
            ans.push_back(root->val);
            root = root->right;
        };
        return ans;
    }
};