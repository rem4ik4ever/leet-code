class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = {}

    def add(self, key: int) -> None:
        if self.data.get(key) is None:
            self.data[key] = True
            return self.data[key]

    def remove(self, key: int) -> None:
        if self.data.get(key):
            del self.data[key]

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        if self.data.get(key):
            return True
        return False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
