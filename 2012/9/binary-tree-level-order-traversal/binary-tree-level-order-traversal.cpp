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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        vector<int> base;
        base.push_back(root->val);
        ans.push_back(base);
        vector<vector<int>> left = levelOrder(root->left), right = levelOrder(root->right);
        for(int i = 0; i < left.size(); ++ i)
        {
            vector<int> temp = left[i];
            if(i < right.size())
                for(int j = 0; j < right[i].size(); ++ j)
                    temp.push_back(right[i][j]);
            ans.push_back(temp);
        }
        if(right.size() > left.size())
        {
            for(int i = left.size(); i < right.size(); ++ i)
                ans.push_back(right[i]);
        }
        return ans;
    }
};