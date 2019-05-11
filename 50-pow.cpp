#include <iostream>

using namespace std;


class Solution {
public:
    double myPow(double x, long long n) {
      if (n < 0) {
        x = 1 / x;
        n = abs(n);
      }
      if (n == 0) {
        return 1;
      }
      return myPow(x * x, n / 2) * (n % 2 > 0 ? x : 1);
    }
};


int main() {
  Solution s = Solution();
  cout << s.myPow(2.00000, -2);
  return 0;
}