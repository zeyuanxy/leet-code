/* 
* @Author: Zeyuan Shang
* @Date:   2015-10-31 17:10:10
* @Last Modified by:   Zeyuan Shang
* @Last Modified time: 2015-10-31 17:10:19
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int inTree(TreeNode* root, int index) {
        
    }
public:
    int countNodes(TreeNode* root) {
        if (not root) {
            return 0;
        }
        TreeNode* l = root;
        int hl = 1;
        while (l) {
            l = l->left;
            hl <<= 1;
        }
        TreeNode* r = root;
        int hr = 1;
        while (r) {
            r = r->right;
            hr <<= 1;
        }
        if (hl == hr) {
            return hl - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};