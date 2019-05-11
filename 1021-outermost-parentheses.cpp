#include <iostream>

using namespace std;


class Solution {
public:
    string removeOuterParentheses(string S) {
        bool hasInner = false;
        int idx = 0, count = 0;
        string res = "";
        while(idx < S.length()){
          if(S[idx] == ')' && count == 1 && hasInner) {
            hasInner = false;
            --count;
          } else if(S[idx] == '(') {
            ++count;
            if(!hasInner && count > 1){
              hasInner = true;
            }
            
          } else {
            --count;
          }
          if(hasInner) res += S[idx];
          ++idx;
        }
        return res;
    }
};

int main(){
  Solution s;
  string res = s.removeOuterParentheses("()()(())");
  cout << res << endl;
}