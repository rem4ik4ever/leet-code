#include <iostream>
#include <vector>

using namespace std;

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