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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        int cnt = 0;
        while (p != NULL || !st.empty()) {
            if (p != NULL) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                if (++cnt == k) {
                    return p->val;
                }
                p = p->right;
            }
        }
    }
};