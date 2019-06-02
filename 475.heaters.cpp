#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findRadius(vector<int> &houses, vector<int> &heaters)
  {
    int radius = 0;
    int distance = 0;
    int st = 0, j;
    for (int i = 0; i < heaters.size(); ++i)
    {
      for (int j = st; j < houses.size(); ++j)
      {
        if (heaters[i] == j + 1)
        {
          if (st == 0)
          {
            distance = j;
            if (j != 0 && distance >= 2)
            {
              distance /= 2;
            }
          }
          else
          {
            cout << j << " " << st << endl;
            int t = (j - st);
            if (t >= 2)
            {
              t = t / 2;
            }
            distance = max(distance, t);
          }
          st = j;
          continue;
        }
      }
    }
    distance = max(distance, (int)houses.size() - 1 - st);
    return distance;
  }
};

int main()
{

  Solution s;
  vector<int> houses = {1, 5};
  vector<int> heaters = {2};
  cout << s.findRadius(houses, heaters) << endl;
  return 0;
}