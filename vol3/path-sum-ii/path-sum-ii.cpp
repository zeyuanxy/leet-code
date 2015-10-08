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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        if(root == NULL)
            return ans;
        if(root->val == sum && root->left == NULL && root->right == NULL) {
            vector<int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);
            return ans;
        }        
    
        vector<vector<int> > leftPath = pathSum(root->left, sum - root->val), rightPath = pathSum(root->right, sum - root->val);
        for(int i = 0; i < leftPath.size(); ++ i) {
            vector<int> temp;
            temp.push_back(root->val);
            for(int j = 0; j < leftPath[i].size(); ++ j)
                temp.push_back(leftPath[i][j]);
            ans.push_back(temp);
        }
        for(int i = 0; i < rightPath.size(); ++ i) {
            vector<int> temp;
            temp.push_back(root->val);
            for(int j = 0; j < rightPath[i].size(); ++ j)
                temp.push_back(rightPath[i][j]);
            ans.push_back(temp);
        }
        return ans;
    }
};