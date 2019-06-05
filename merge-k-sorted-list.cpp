/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Runtime: 28 ms, faster than 86.36% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 11.9 MB, less than 39.50% of C++ online submissions for Merge k Sorted Lists.

//Complexity O(N) where N number of List Nodes
// Space O(N) where N number of nodes saved in queue
class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {

    priority_queue<pair<int, ListNode *>> que;
    for (int i = 0; i < lists.size(); ++i)
    {
      ListNode *nd = lists[i];
      while (nd)
      {
        que.push(make_pair(nd->val, nd));
        nd = nd->next;
      }
    }
    ListNode *result = NULL;
    while (!que.empty())
    {
      if (result == NULL)
      {
        que.top().second->next = NULL;
        result = que.top().second;
      }
      else
      {
        que.top().second->next = result;
        result = que.top().second;
      }
      que.pop();
    }

    return result;
  }
};