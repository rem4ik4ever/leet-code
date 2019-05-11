#include <iostream>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        const int diff = 'a' - 'A';
        cout << (int)'A' << endl;
        cout << (int)'Z' << endl;
        for (string::iterator it = str.begin(); it != str.end(); it++)
        {
          if(*it >= 'A' && *it <= 'Z') {
            *it = *it + diff;
          }
        }
        
        return str;
    }
};


int main() {
  Solution s;
  string res = s.toLowerCase("HelloZ");
  cout << res << endl;
  return 0;
}