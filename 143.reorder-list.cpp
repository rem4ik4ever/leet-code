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

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        //First find middle of the list

        ListNode *slow = head;
        ListNode *fast = head;
        while (slow->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reverse half after middle
        ListNode *preMiddle = slow;
        ListNode *preCurrent = slow->next;
        while (preCurrent != NULL)
        {
            ListNode *current = preCurrent->next;
            preCurrent->next = current->next;
            current->next = preMiddle->next;
            preMiddle->next = current;
        }
    }
};

int main()
{

    return 0;
}