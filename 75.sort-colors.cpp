#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 
 * 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
 * Memory Usage: 8.6 MB, less than 56.18% of C++ online submissions for Sort Colors.
 * 
 * Complexity O(N)
 * Space O(1)
 * 
 * 
 * */

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return;
        }
        vector<int>::iterator st = nums.begin();
        vector<int>::iterator et = nums.end() - 1;

        while (*st == 0 && st < et)
        {
            ++st;
        }
        while (*et == 2 && et > st)
        {
            --et;
        }

        vector<int>::iterator move = st;
        while (move <= et && st < et && st < nums.end() && move < nums.end() && et >= nums.begin())
        {
            if (*move == 0)
            {
                int tmp = *move;
                *move = *st;
                *st = tmp;
                ++st;
                move = st;
            }
            else if (*move == 2)
            {
                int tmp = *move;
                *move = *et;
                *et = tmp;
                --et;
            }
            else
            {
                ++move;
            }
        }
    }
};
void print_array(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main()
{
    Solution s;

    vector<int> v = {1, 0, 1, 1, 1, 0};
    s.sortColors(v);
    print_array(v);

    vector<int> v1 = {1, 1};
    s.sortColors(v1);
    print_array(v1);

    vector<int> v2 = {0, 0};
    s.sortColors(v2);
    print_array(v2);

    vector<int> v3 = {1, 2, 0};
    s.sortColors(v3);
    print_array(v3);

    vector<int> v4 = {2, 0, 2, 1, 1, 0};
    s.sortColors(v4);
    print_array(v4);

    vector<int> v5 = {2, 2};
    s.sortColors(v5);
    print_array(v5);

    vector<int> v6 = {2, 1};
    s.sortColors(v6);
    print_array(v6);
}