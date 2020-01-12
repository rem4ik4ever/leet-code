
def maxDepthAfterSplit(seq):
    """
    :type seq: str
    :rtype: List[int]
    """

    res = []
    a, b = 0, 0
    for c in seq:
      if c == '(':
          if a < b: 
            res.append(0)
            a += 1
          else:
            res.append(1)
            b += 1
      else:
          if a > b:
            res.append(0)
            a -= 1
          else:
            res.append(1)
            b -= 1
    return res

print(maxDepthAfterSplit('()(())()'))

