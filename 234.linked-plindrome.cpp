#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Runtime: 20 ms, faster than 97.20% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 13.3 MB, less than 26.11% of C++ online submissions for Palindrome Linked List.

// Complexity O(N)
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        int fastCount = 0, slowCount = 0;
        while (fast && fast->next)
        {
            fast = fast->next;
            ++fastCount;
            if (fast->next)
            {
                fast = fast->next;
                ++fastCount;
            }
            slow = slow->next;
            ++slowCount;
        }
        int addCount = fastCount - slowCount + 1;
        stack<int> stk;

        while (addCount != 0)
        {
            stk.push(head->val);
            head = head->next;
            --addCount;
        }
        while (slow)
        {
            if (stk.top() != slow->val)
            {
                return false;
            }
            stk.pop();
            slow = slow->next;
        }
        //By that time slow is in pre middle section

        return true;
    }
    void print_linked_list(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << ' ';
            head = head->next;
        }
        cout << endl;
    }
};

int main()
{
    // 1 - 2 - 3 - 2 - 1
    // 1 - 2 - 2 - 1
    ListNode *head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(3);
    // head->next->next->next->next = new ListNode(1);
    Solution s;
    cout << s.isPalindrome(head) << endl;
    return 0;
}