# Definition for a binary tree node.
class TreeNode(object):
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None

class Solution(object):
  def delNodes(self, root, to_delete):
    """
    :type root: TreeNode
    :type to_delete: List[int]
    :rtype: List[TreeNode]
    """
    def traverseDelete(prev, root, roots, to_delete, just_deleted):
      if root == None or root.val == None:
        return
      if root.val in to_delete:
        just_deleted = True
        if prev and prev.left and prev.left.val == root.val:
          prev.left = None
        elif prev:
          prev.right = None
      else:
        if just_deleted:
          roots.append(root)
          just_deleted = False
      traverseDelete(root ,root.left, roots, to_delete, just_deleted)
      traverseDelete(root ,root.right, roots, to_delete, just_deleted)
    roots = []
    to_delete = set(to_delete)
    traverseDelete(None, root, roots, to_delete, True)
    return roots
