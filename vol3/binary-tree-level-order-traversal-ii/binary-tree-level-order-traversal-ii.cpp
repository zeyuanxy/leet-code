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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if(root == NULL)
            return ans;
        vector<vector<int> > left = levelOrderBottom(root->left), right = levelOrderBottom(root->right);
        if(right.size() > left.size())
        {
            for(int i = 0; i < (int)right.size() - (int)left.size(); ++ i)
                ans.push_back(right[i]);
        }
        for(int i = 0; i < left.size(); ++ i)
        {
                vector<int> temp = left[i];
                if(i + right.size() >= left.size())
                    for(int j = 0; j < right[right.size() + i - left.size()].size(); ++ j)
                        temp.push_back(right[right.size() + i - left.size()][j]);
                ans.push_back(temp);
        }

        vector<int> base;
        base.push_back(root->val);
        ans.push_back(base);
        return ans;
    }
};