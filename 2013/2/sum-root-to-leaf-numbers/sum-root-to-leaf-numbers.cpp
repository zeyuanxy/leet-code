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
    void sumPath(TreeNode *root, int prevSum, int &totalSum)
    {
        if(root == NULL)
            return;
        prevSum = prevSum * 10 + root->val;
        
        if(root->left == NULL && root->right == NULL)
        {
            totalSum += prevSum;
            return;
        }
        sumPath(root->left, prevSum, totalSum);
        sumPath(root->right, prevSum, totalSum);
    }
    
    
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sumPath(root, 0, sum);
        return sum;
    }
};