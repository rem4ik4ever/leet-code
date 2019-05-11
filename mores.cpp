#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    unordered_map<string, int> umap;
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {

        for (int i = 0; i < words.size(); i++)
        {
          // cout << printMorse(words[i]) << endl;
          string word = printMorse(words[i]);
          umap[word] = umap[word] ? umap[word]++ : umap[word] = 1;
        }
        return umap.size();
    }
    int getCharIndex(char c){
      return (int)c - 97;
    }

    string printMorse(string word){
      string res = "";
      for (int i = 0; i < word.length(); i++)
      {
        res += morse[getCharIndex(word[i])];
      }
      return res;
    }
};


int main() {
  Solution s;  
  vector<string> input = {"gin", "zen", "gig", "msg"};
  int size = s.uniqueMorseRepresentations(input);
  cout << size << endl;
  return 0;
}