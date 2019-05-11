#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
      unordered_map<int, int> umap;
      umap.reserve(A.size());
      for (int i = 0; i < B.size(); i++)
      {
        if(umap.find(B[i]) == umap.end()){
          umap[B[i]] = i;
        }
      }
      vector<int> res;
      for (int i = 0; i < A.size(); i++)
      {
        res.push_back(umap[A[i]]);
      }
      return res;
    }
};


int main() {
  Solution s;
  vector<int> b = {50, 12, 32, 46, 28};
  vector<int> a = {12, 28, 46, 32, 50};
  vector<int> res = s.anagramMappings(a, b);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i];
    cout << ", ";
  }
  
  
  return 0;
}