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
    TreeNode *divide(vector<int> &num, int l, int r)
    {
        if(l > r)
            return NULL;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = divide(num, l, mid - 1);
        root->right = divide(num, mid + 1, r);
        return root;
    }


    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0)
            return NULL;
        return divide(num, 0, num.size() - 1);
    }
};