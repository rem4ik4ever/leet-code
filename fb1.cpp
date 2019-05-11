#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    unordered_map<string, int> populateMap() {
      unordered_map<string, int> umap;
      umap["I"] = 1;
      umap["V"] = 5;
      umap["IV"] = 4;
      umap["X"] = 10;
      umap["IX"] = 9;
      umap["L"] = 50;
      umap["XL"] = 40;
      umap["C"] = 100;
      umap["XC"] = 90;
      umap["D"] = 500;
      umap["CD"] = 400;
      umap["M"] = 1000;
      umap["CM"] = 900;
      return umap;
    }
    int romanToInt(string s) {
       unordered_map <string, int> umap = populateMap();
        string::iterator it = s.begin();
        int res = 0;
        while(it != s.end()){
          string singleChar = "";
          singleChar.push_back(*it);
          string doubleChar = singleChar;
          doubleChar.push_back(*(it + 1));

          if(umap[doubleChar]) {
            res += umap[doubleChar];
            ++it;
          } else {
            res += umap[singleChar];
          }
          ++it;
        }
        return res;
    }
};


int main() {
  Solution s;
  int res = s.romanToInt("MCMXCIV");
  cout << res << endl;
  return 0;
}

