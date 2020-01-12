class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        def canInsert(flowerbed, index):
            if len(flowerbed) == 1:
                return True
            if index - 1 >= 0 and index + 1 < len(flowerbed):
                return flowerbed[index-1] != 1 and flowerbed[index + 1] != 1
            if index == 0:
                return flowerbed[index + 1] != 1
            if index == len(flowerbed) - 1:
                return flowerbed[index - 1] != 1

        for i in range(0, len(flowerbed)):
            if flowerbed[i] == 0 and canInsert(flowerbed, i):
                flowerbed[i] = 1
                n -= 1
        if n > 0:
            return False
        return True
