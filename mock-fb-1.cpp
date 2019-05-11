#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// Solution 1;
// Complexity (n * (n-1)) O(n**2)
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//       int maxProfit = 0;
//         for (int i = 0; i < prices.size(); i++)
//         {
//           for (int j = i + 1; j < prices.size(); j++)
//           {
//             if(prices[j] - prices[i] > maxProfit){
//               maxProfit = prices[j] - prices[i];
//             }
//           }
          
//         }
//         return maxProfit;
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
      unordered_map<int, int> umap;
      for (int i = 0; i < prices.size(); i++)
      {
        umap[prices[i]] = i;
      }
      
      sort(prices.begin(), prices.end());

      vector<int>::iterator start = prices.begin();
      vector<int>::iterator end = prices.end();
      bool found = false;
      int profit = 0;
      while(!found || end != prices.begin()){
        cout << umap[*start] << " " << umap[*end] << endl;
        if(umap[*start] < umap[*end]) {
          found = true;
          profit = *end - *start;
          break;
        } else {
          ++start;
        }
        if(start == end){
          start = prices.begin();
          --end;
        }
      }
      return profit;
        
    }
};

int main(){
  Solution s;
  vector<int> input = {7,6,4,3,1,7,6,4,3,1,7,6,4,3,1,7,6,4,3,1,7,6,4,3,1};
  cout << s.maxProfit(input) << endl;
  return 0;
}