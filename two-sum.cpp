#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        cout << 1 + (num - 1) % 9 << endl;
        return 1 + (num - 1) % 9;
    }
};


int main(){
  Solution s;
  s.addDigits(9);
  return 0;
}