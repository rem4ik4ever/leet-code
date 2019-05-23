#include <iostream>
#include <vector>
#include <bitset>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    int pos = 0;
    unordered_map<ListNode *, bool> visited;
    visited[head] = true;

    while (head != NULL || visited[head])
    {
      head = head->next;
      visited[head] = true;
      ++pos;
    }
    return head;
  }
};

// int main()
// {
//   Solution s;
//   cout << s.detectCycle(v) << endl;
//   return 0;
// }
