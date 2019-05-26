#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Runtime: 4 ms, faster than 98.06% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 8.6 MB, less than 65.65% of C++ online submissions for Remove Nth Node From End of List.

// Complexity O(N) where N number of list nodes
// Space O(1)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        int slowCount = 0, fastCount = 0;
        // Fast is total nums of list items
        // Slow is w/e

        while (fast)
        {
            slow = slow->next;
            slowCount++;
            fast = fast->next;
            fastCount++;
            if (fast && fast->next != NULL)
            {
                fast = fast->next;
                fastCount++;
            }
        }
        if (n - fastCount >= 0)
        {
            head = head->next;
            return head;
        }
        // Reset slow count and slow pointer if N is before Slow pointer
        if (fastCount - slowCount <= n)
        {
            slowCount = 0;
            slow = head;
        }

        // We need to move Slow pointer before Nth ListNode in order to remove it
        while (fastCount - slowCount != n + 1)
        {
            slowCount++;
            slow = slow->next;
        }

        // Remove Nth node connecting over it
        ListNode *next = slow->next;
        slow->next = next->next;

        return head;
    }
};
int main()
{
    return 0;
}