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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans, flag;
        vector<TreeNode*> stack;
        while(root)
        {
            stack.push_back(root);
            flag.push_back(0);
            root = root->left;
        }
        while(!stack.empty())
        {
            root = stack[stack.size() - 1];
            while(root->right && flag[stack.size() - 1] == 0)
            {
                flag[stack.size() - 1] = 1;
                root = root->right;
                while(root)
                {
                    stack.push_back(root);
                    flag.push_back(0);
                    root = root->left;
                }
                root = stack[stack.size() - 1];
            }
            root = stack[stack.size() - 1];
            stack.pop_back();
            flag.pop_back();
            ans.push_back(root->val);
        }
        return ans;
    }
};