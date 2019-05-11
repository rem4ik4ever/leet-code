#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    }
private:
    int getMaxSequence(vector<int> nums, int startIndex){
      
    }
};


int main(){
  vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
  Solution s;
  int res = s.maxSubArray(input);
  cout << res << endl;
  return 0;
}