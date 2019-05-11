#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 * Two pointer solution
 * 
 * Discussion:
 *  Complexity O(N) 
 *  Space O(N)
 * 
 * This solution is very fast and elegant. Probably one of the best approaches to solve this kind of problem.
 * 
 * Brute force solution is much slover 
 *  Complexity O(N^2)
 *  Where max will be calculated same way however calculation will have to loop through double for loops
 * 
 * Runtime: 20 ms, faster than 97.55% of C++ online submissions for Container With Most Water.
 * Memory Usage: 9.8 MB, less than 98.61% of C++ online submissions for Container With Most Water.
 * 
 * */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVolume = 0;
        int s = 0, e = height.size() - 1;
        while(s < e) {
            maxVolume = max(maxVolume, min(height[s], height[e]) * (e - s));
            height[s] <= height[e] ? ++s : --e;
        }
        return maxVolume;
    }
};


int main() {
    Solution s;
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(v) << endl;
  return 0;
}