# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root == None:
            return []
        if root.left == None and root.right == None:
            return [str(root.val)]
        ret = []
        if root.left != None:
            left = self.binaryTreePaths(root.left)
            left = map(lambda x: str(root.val) + '->' + x, left)
            ret += left
        if root.right != None:
            right = self.binaryTreePaths(root.right)
            right = map(lambda x: str(root.val) + '->' + x, right)
            ret += right
        return ret