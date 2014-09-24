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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        vector<TreeNode*> stack;
        stack.push_back(root);
        while(stack.size() > 0)
        {
            root = stack[stack.size() - 1];
            stack.pop_back();
            ans.push_back(root->val);
            if(root->right != NULL)
                stack.push_back(root->right);
            if(root->left != NULL)
                stack.push_back(root->left);
        }
        return ans;
    }
};