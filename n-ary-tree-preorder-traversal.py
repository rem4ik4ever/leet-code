"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution(object):
    def __init__(self):
        self.lst = []

    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if root is None:
            return None
        self.lst.append(root.val)
        for child in root.children:
            self.preorder(child)
        return self.lst
