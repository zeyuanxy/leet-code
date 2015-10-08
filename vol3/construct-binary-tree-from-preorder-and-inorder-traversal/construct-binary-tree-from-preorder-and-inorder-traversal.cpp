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
    
    TreeNode *build(vector<int>::iterator pre_begin, vector<int>::iterator pre_end, vector<int>::iterator in_begin, vector<int>::iterator in_end) {
        if(pre_begin == pre_end)
            return NULL;
        
        TreeNode *root = new TreeNode(*pre_begin);
        for(vector<int>::iterator i = in_begin; i < in_end; ++ i)
            if(*i == root->val)
            {
                root->left = build(pre_begin + 1, pre_begin + 1 + (i - in_begin), in_begin, i);
                root->right = build(pre_begin + 1 + (i - in_begin), pre_end, i + 1, in_end);
                return root;
            }
        return NULL;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};