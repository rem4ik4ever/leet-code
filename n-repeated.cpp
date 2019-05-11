#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 80ms slow O(n)
// class Solution {
// public:
//     int repeatedNTimes(vector<int>& A) {
//         unordered_map<int, int> umap;
//         int max = 0;
//         int val = 0;
//         int nMax = A.size() / 2;
//         for (int i = 0; i < A.size(); i++)
//         {
//           if(!umap[A[i]]) {
//             umap[A[i]] = 1;
//           } else {
//             umap[A[i]]++;
//           }
//           if(umap[A[i]] > max && umap[A[i]] <= nMax){
//             max = umap[A[i]];
//             val = A[i];
//           }
//         }
//         return val;
//     }
// };

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(), A.end());
        if(A[(A.size() - 1) / 2] == A[(A.size() - 1) / 2 - 1]) {
          return A[A.size() / 2 - 1];
        } else if (A[A.size() / 2] == A[A.size() / 2 + 1]){
          return A[A.size() / 2 + 1];
        } 
        return 0;
    }

    void print_array(vector<int> vec){
      for (int i = 0; i < vec.size(); i++)
      {
        cout << vec[i] << ", ";
      }
      cout << endl;
      
    }
};





int main(){
  vector<int> i = {9,5,3,3};
  Solution s;
  int res = s.repeatedNTimes(i);
  cout << res << endl;
  return 0;
}