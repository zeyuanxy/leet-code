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
    TreeNode *build(vector<int>::iterator in_begin, vector<int>::iterator in_end, vector<int>::iterator post_begin, vector<int>::iterator post_end) {
        if(in_begin == in_end)
            return NULL;
        
        TreeNode *root = new TreeNode(*(post_end - 1));
        for(vector<int>::iterator i = in_begin; i < in_end; ++ i)
            if(*i == root->val)
            {
                root->left = build(in_begin, i, post_begin, post_begin + (i - in_begin));
                root->right = build(i + 1, in_end, post_begin + (i - in_begin), post_end - 1);
                return root;
            }
        return NULL;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};