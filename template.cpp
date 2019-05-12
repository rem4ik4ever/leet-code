#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> v)
{
  for (int i = 0, j = v.size() - 1; i < j; i++, --j)
  {
    swap(v[i], v[j]);
  }
}

void print_array(vector<int> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << ", ";
  }
  cout << endl;
}

void printMatrix(vector<vector<int>> matrix)
{
  for (int i = 0; i < matrix.size(); i++)
  {
    cout << "[ ";
    for (int j = 0; j < matrix[i].size(); j++)
    {
      if (j > 0)
      {
        cout << ", ";
      }
      cout << matrix[i][j];
    }
    cout << " ]" << endl;
  }
}

int main()
{

  return 0;
}