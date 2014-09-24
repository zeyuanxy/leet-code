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
    vector<TreeNode *> generateRange(int start, int end)
    {
        vector<TreeNode *> ans;
        if(start > end) {
            ans.push_back(NULL);
            return ans;
        }
        
        for(int i = start; i <= end; ++ i)
        {
            vector<TreeNode *> l = generateRange(start, i - 1);
            vector<TreeNode *> r = generateRange(i + 1, end);
            for(int j = 0; j < l.size(); ++ j)
                for(int k = 0; k < r.size(); ++ k) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l[j];
                    root->right = r[k];
                    ans.push_back(root);
                }
        }
        return ans;
    }

    vector<TreeNode *> generateTrees(int n) {
        return generateRange(1, n);
    }
};