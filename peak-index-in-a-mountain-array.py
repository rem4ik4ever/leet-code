class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        if len(A) < 3:
            return None

        for i in range(1, len(A) - 1):
            if A[i] > A[i - 1] and A[i] > A[i + 1]:
                return i
        return None
