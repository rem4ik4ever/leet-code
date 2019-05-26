#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        queue<int> nums1;
        queue<int> nums2;
        int n1 = 0;
        int n2 = 0;

        while (l1 != NULL)
        {
            nums1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            nums2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *result = new ListNode(0);
        ListNode *current = result;
        int tmp = 0;
        while (nums1.size() > 0 || nums2.size() > 0)
        {
            int sum = tmp;
            if (!nums1.empty())
            {
                sum += nums1.front();
                nums1.pop();
            }
            if (!nums2.empty())
            {
                sum += nums2.front();
                nums2.pop();
            }

            current->next = new ListNode(sum % 10);
            tmp = sum > 9 ? 1 : 0;
            current = current->next;
        }
        if (tmp)
        {
            current->next = new ListNode(tmp);
        }
        return result->next;
    }
};

int main()
{

    return 0;
}