#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 
 * Reverse to Task Roman to Integer
 * 
 * 
 * */

class Solution
{
public:
  unordered_map<int, string> romanNumberMap()
  {
    unordered_map<int, string> umap;
    umap.reserve(13);
    umap[1] = "I";
    umap[5] = "V";
    umap[4] = "IV";
    umap[10] = "X";
    umap[9] = "IX";
    umap[50] = "L";
    umap[40] = "XL";
    umap[100] = "C";
    umap[90] = "XC";
    umap[500] = "D";
    umap[400] = "CD";
    umap[1000] = "M";
    umap[900] = "CM";
    return umap;
  }

  string reverse(string st)
  {
    int n = st.length();
    for (int i = 0; i < n / 2; i++)
    {
      swap(st[i], st[n - i - 1]);
    }
    return st;
  }

  string intToRoman(int num)
  {
    string res = "";
    unordered_map<int, string> romanNums = romanNumberMap();
    int mp = 10;
    while (num != 0)
    {
      int toRom = num % mp;
      num -= num % mp;
      if (romanNums.find(toRom) != romanNums.end())
      {
        res.append(reverse(romanNums[toRom]));
      }
      else
      {
        while (toRom > 0)
        {
          if (toRom < 4)
          {
            while (toRom > 0)
            {
              res = romanNums[1] + res;
              toRom--;
            }
          }
          else if (toRom < 10 && toRom > 4)
          {
            res = romanNums[5] + res;
            toRom -= 5;
          }
          else if (toRom > 50 && toRom < 100)
          {

            while (toRom - 50 > 0)
            {
              res = res + romanNums[10];
              toRom -= 10;
            }
            res += romanNums[50];
            toRom -= 50;
          }
          else if (toRom > 500 && toRom < 1000)
          {
            while (toRom - 500 > 0)
            {
              res = res + romanNums[100];
              toRom -= 100;
            }
            res += romanNums[500];
            toRom -= 500;
          }
          else
          {
            while (toRom > 0)
            {
              res = res + romanNums[mp / 10];
              toRom -= mp / 10;
            }
          }
        }
      }
      mp *= 10;
    }
    return reverse(res);
  }
};

int main()
{
  Solution s;
  cout << s.intToRoman(3) << endl;
  cout << s.intToRoman(4) << endl;
  cout << s.intToRoman(10) << endl;
  cout << s.intToRoman(20) << endl;
  cout << s.intToRoman(58) << endl;
  cout << s.intToRoman(60) << endl;
  cout << s.intToRoman(61) << endl;
  cout << s.intToRoman(600) << endl;
  cout << s.intToRoman(601) << endl;
  cout << s.intToRoman(1994) << endl;
  cout << s.intToRoman(3999) << endl;
  return 0;
}