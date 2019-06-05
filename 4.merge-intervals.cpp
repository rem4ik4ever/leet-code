// Runtime: 16 ms, faster than 75.87% of C++ online submissions for Merge Intervals.
// Memory Usage: 13 MB, less than 8.74% of C++ online submissions for Merge Intervals.

// Complexity O(N)
// Space O(N)
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {

    vector<vector<int>> result;
    if (intervals.size() == 0)
    {
      return result;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < intervals.size(); ++i)
    {
      auto p = make_pair(intervals[i][0], intervals[i][1]);
      v.push_back(p);
    }

    sort(v.begin(), v.end());

    auto initial = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
      if (initial.second >= v[i].first && initial.second <= v[i].second)
      {
        initial.second = v[i].second;
      }
      else if (initial.first < v[i].first && initial.second < v[i].first)
      {
        vector<int> r = {initial.first, initial.second};
        result.push_back(r);
        initial = v[i];
      }
    }
    vector<int> r = {initial.first, initial.second};
    result.push_back(r);

    return result;
  }
};