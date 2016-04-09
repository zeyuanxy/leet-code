# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob_recursive(self, root):
        if root == None:
            return 0, 0
        rob_left, rob_without_left = self.rob_recursive(root.left)
        rob_right, rob_without_right = self.rob_recursive(root.right)
        return root.val + rob_without_left + rob_without_right, max(rob_left, rob_without_left)  + max(rob_right, rob_without_right)
    
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        rob_root, rob_without_root = self.rob_recursive(root)
        return max(rob_root, rob_without_root)