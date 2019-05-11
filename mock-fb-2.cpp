#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> res(nums.size(), 0);

      int p = 1;
      for (int i = 0; i < nums.size(); i++)
      {
        res[i] = p;;
        p *= nums[i];
      }
      p = 1;
      for (int i = nums.size() -1 ; i >= 0; i--)
      {
        res[i] *= p;;
        p *= nums[i];
      } 
      return res;
    }
  private:
    void print_array(vector<int> &v){
      cout << "arr: ";
      for (int i = 0; i < v.size(); i++)
      {
        cout << v[i] << " ";
      }
      cout << endl;
    }
};

int main(){
  Solution s;
  vector<int> input = {1,2,3,4};
  s.productExceptSelf(input);
  return 0;
}