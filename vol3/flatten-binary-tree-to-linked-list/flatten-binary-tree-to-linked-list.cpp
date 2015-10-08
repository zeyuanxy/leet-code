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
    TreeNode *convert2List(TreeNode *root) {
        if(root == NULL)
            return NULL;
            
        TreeNode *l = convert2List(root->left), *r = convert2List(root->right);
        if(l != NULL) {
            l->right = root->right;
            root->right = root->left;
        }
        root->left = NULL;
        if(r != NULL)
            return r;
        else if(l != NULL)
            return l;
        else
            return root;
    }

    void flatten(TreeNode *root) {
        convert2List(root);
    }
};