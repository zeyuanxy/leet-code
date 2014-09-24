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
    TreeNode *prev, *m1, *m2;
public:
    void findMistake(TreeNode *root) {
        if(root == NULL)
            return;
        findMistake(root->left);
        if(prev != NULL && prev->val > root->val)
        {
            if(m1 == NULL)
                m1 = prev;
            m2 = root;
        }
        prev = root;
        findMistake(root->right);
    }

    void recoverTree(TreeNode *root) {
        if(root == NULL)
            return;
        prev = NULL;
        m1 = NULL;
        m2 = NULL;
        findMistake(root);
        swap(m1->val, m2->val);
    }
};