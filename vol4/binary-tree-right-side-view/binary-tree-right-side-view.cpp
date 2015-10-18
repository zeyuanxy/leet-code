/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) {
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *top = q.front();
                q.pop();
                if (i == 0) {
                    ret.push_back(top->val);
                }
                if (top->right != NULL) {
                    q.push(top->right);
                }
                if (top->left != NULL) {
                    q.push(top->left);
                }
            }
        }
        return ret;
    }
};