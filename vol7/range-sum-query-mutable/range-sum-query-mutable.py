class SegmentTreeNode(object):
    def __init__(self, nums):
        n = len(nums)
        if n == 1:
            self.left = None
            self.right = None
            self.value = nums[0]
        else:
            self.left = SegmentTreeNode(nums[:n / 2])
            self.right = SegmentTreeNode(nums[n / 2:])
            self.value = self.left.value + self.right.value
        self.size = n
    
    def update(self, index, value):
        if self.size == 1:
            self.value = value
        elif index < self.size / 2:
            self.left.update(index, value)
            self.value = self.left.value + self.right.value
        else:
            self.right.update(index - self.size / 2, value)
            self.value = self.left.value + self.right.value
            
    def query(self, leftRange, rightRange):
        if self.size == 1:
            return self.value
        elif leftRange == 0 and rightRange == self.size - 1:
            return self.value
        elif leftRange >= self.size / 2:
            return self.right.query(leftRange - self.size / 2, rightRange - self.size / 2)
        elif rightRange < self.size / 2:
            return self.left.query(leftRange, rightRange)
        else:
            return self.left.query(leftRange, self.size / 2 - 1) + self.right.query(0, rightRange - self.size / 2)

class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        if not nums:
            return 
        self.root = SegmentTreeNode(nums)
        

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: int
        """
        self.root.update(i, val)
        

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.root.query(i, j)
        


# Your NumArray object will be instantiated and called as such:
# numArray = NumArray(nums)
# numArray.sumRange(0, 1)
# numArray.update(1, 10)
# numArray.sumRange(1, 2)