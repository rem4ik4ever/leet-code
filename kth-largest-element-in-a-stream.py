class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.nums = sorted(nums)
        self.k = k

    def add(self, val: int) -> int:
        index = self.findIndex(val, 0, len(self.nums)-1)
        self.nums.insert(index, val)
        return self.nums[-self.k]

    def findIndex(self, val, low, high):
        if low > high:
            return low
        pivot = (low + high) // 2
        if self.nums[pivot] == val:
            return pivot
        if val < self.nums[pivot]:
            return self.findIndex(val, low, pivot - 1)
        if val > self.nums[pivot]:
            return self.findIndex(val, pivot + 1, high)
# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
