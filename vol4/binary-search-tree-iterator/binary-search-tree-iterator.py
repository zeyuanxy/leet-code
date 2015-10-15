# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.root = root
        self.iterator = root
        self.path = []
        if root == None:
            return
        while self.iterator.left != None:
            self.path.append(self.iterator)
            self.iterator = self.iterator.left
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return (self.iterator != None)
        

    def next(self):
        """
        :rtype: int
        """
        ret = self.iterator.val    
    
        if self.iterator.right != None:
            self.path.append(self.iterator)
            self.iterator = self.iterator.right
            while self.iterator.left != None:
                self.path.append(self.iterator)
                self.iterator = self.iterator.left
        else:
            next_iterator = None
            while True:
                if len(self.path) == 0:
                    next_iterator = None
                    break
                next_iterator = self.path[-1]
                self.path = self.path[:-1]
                if next_iterator.val > ret:
                    break
            self.iterator = next_iterator
            
        return ret
        

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())