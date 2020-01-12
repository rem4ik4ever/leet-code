# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def areSame(self, s, t):
        if s == None and t == None:
            return True
        if s == None or t == None:
            return False
        return s.val == t.val and self.areSame(s.left, t.left) and self.areSame(s.right, t.right)

    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        if s == None and t == None:
            return True
        if s == None or t == None:
            return False
        return self.areSame(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
