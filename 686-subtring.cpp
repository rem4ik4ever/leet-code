#include <iostream>

using namespace std;


class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string res = "";
        bool found = false;
        int count = 1;
        if(A.length() > B.length()){
          return (int)A.find(B) > -1 ? 1 : ((int)(A + A).find(B) > -1 ? 2 : -1);
        }
        while(res.length() < B.length() * 4){
          res += A;
          cout << res << endl;
          if((int)res.find(B) > -1) {
            found = true;
            cout << res << endl;
            break;
          }
          ++count;
        }
        if(found) {
          return count;
        }
        return  -1;
    }
};


int main(){
  Solution s;
  int res = s.repeatedStringMatch("abcd", "cdabcdab");
  cout << res << endl;
  return 0;
}
// "abcd"
// "cdabcdab"


// "aaaaaaaaaaaaaaaaaaaaaab"
// "ba"

// //abaabaaabaabaaabaabaa\
// "abaabaa"
// "abaababaab"