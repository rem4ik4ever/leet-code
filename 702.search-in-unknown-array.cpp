#include <iostream>
#include <vector>

using namespace std;

// Forward declaration of ArrayReader class.
/**
 * 
 * 
 * Solution 1
 * Discussion:
  * This solution is based on the fact that we don't know array length
  * Otherwise this could be easily be solved with Binary Search in O(logN)
 * 
 * Algorigthm :
 *  Use step variable to quickly skip over array to find boundries 
 *  Multiply step by 2 every time boundry not found
 *  Or if step goes out of boundry reset back to 0
 * 
 *  where Start value >= target and End Value is <= target 
 *  When those boundries are found use BinarySearch to find target
 *  
 *  if boundries not found return -1
 * 
 *  same if binary search could not find target
 * 
 *  Runtime: 56 ms, faster than 41.36% of C++ online submissions for Search in a Sorted Array of Unknown Size.
 *  Memory Usage: 12.3 MB, less than 33.33% of C++ online submissions for Search in a Sorted Array of 
 * 
 * */
class Solution
{
public:
  int search(const ArrayReader &reader, int target)
  {
    int stIdx = 0, vol = 1;
    int found = -1;
    while (found == -1 || reader.get(stIdx) != 2147483647)
    {
      if (reader.get(stIdx + vol) == 2147483647)
      {
        vol /= 2;
      }
      if (reader.get(stIdx) < target && reader.get(stIdx + vol) < target && reader.get(stIdx + vol) != 2147483647)
      {
        stIdx += vol;
        vol *= 2;
      }
      else if (reader.get(stIdx) <= target && reader.get(stIdx + vol) >= target)
      {
        //do binary search
        found = binarySearch(stIdx, stIdx + vol, reader, target);
        break;
      }
      else
      {
        break;
      }
    }
    return found;
  }
  int binarySearch(int start, int end, const ArrayReader &reader, int target)
  {
    int mid = 0;
    int found = -1;
    while (start <= end && found == -1)
    {
      mid = (start + end) / 2;
      if (reader.get(mid) == target)
      {
        return found = mid;
      }
      else if (reader.get(mid) > target)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
    return found;
  }
};

/**
 * 
 * Solution 2
 * 
 * Discussion: 
 *  Try use binary search all the way. Setting End pointer to max integer value
 *  Seems more elegant and twice faster than Soluition 1
 * 
 * Memory wise lacks behind.
 * 
 * 
 * 
 * Runtime: 52 ms, faster than 84.69% of C++ online submissions for Search in a Sorted Array of Unknown Size. 
 * Memory Usage: 12.3 MB, less than 11.90% of C++ online submissions for Search in a Sorted Array of Unknown Size.
 * 
 * Complexity O(LogN)
 * Space O(1)
 * */

class Solution2
{
public:
  int search(const ArrayReader &reader, int target)
  {
    int l = 0, r = 2147483647, mid;
    int found = -1;

    while (found == -1 && l <= r)
    {
      mid = (l + r) / 2;
      if (reader.get(mid) == target)
      {
        return found = mid;
      }

      if (reader.get(mid) == 2147483647 || reader.get(mid) > target)
      {
        r = mid - 1;
      }

      if (reader.get(mid) < target)
      {
        l = mid + 1;
      }
    }
    return found;
  }
};

/**
 * 
 * 
 * Solution 3
 * Recursive version of Solution 2
 * 
 * Recursive solution is a little faster.
 * However takes a bit more memory than Solution 2
 * 
 * Runtime: 48 ms, faster than 87.41% of C++ online submissions for Search in a Sorted Array of Unknown Size.
 * Memory Usage: 12.5 MB, less than 7.14% of C++ online submissions for Search in a Sorted Array of Unknown Size.
 * 
 * Complexity O(LogN)
 * Space O(1)
 * */
class Solution3
{
public:
  int search(const ArrayReader &reader, int target)
  {
    int l = 0, r = 2147483647, mid;

    return binarySearch(l, r, reader, target);
  }

  int binarySearch(int l, int r, const ArrayReader &reader, int target)
  {

    if (r >= 1)
    {
      int mid = (l + r) / 2;
      if (reader.get(mid) == target)
        return mid;

      if (reader.get(mid) == 2147483647 || reader.get(mid) > target)
        return binarySearch(l, mid - 1, reader, target);

      if (reader.get(mid) < target)
        return binarySearch(mid + 1, r, reader, target);
    }
    return -1;
  }
};

int main()
{

  return 0;
}