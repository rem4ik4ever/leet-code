#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * 
 * 
 * Solution 1
 * Runtime: 116 ms, faster than 58.69% of C++ online submissions for 3Sum.
 * Memory Usage: 15.8 MB, less than 97.49% of C++ online submissions for 3Sum.
 * 
 * Complexity O(N^2)
 * Space O(N);
 * 
 * */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> solutions;
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            int target = -nums[i];

            while (left < right)
            {
                if (nums[left] + nums[right] > target)
                {
                    --right;
                }
                else if (nums[left] + nums[right] < target)
                {
                    ++left;
                }
                else
                {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    solutions.push_back(triplet);

                    while (left < right && nums[left] == triplet[1])
                    {
                        ++left;
                    }
                    while (left < right && nums[right] == triplet[2])
                    {
                        --right;
                    }
                }
                while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                {
                    ++i;
                }
            }
        }
        return solutions;
    }
};

/**
 * 
 * Runtime: 92 ms, faster than 99.61% of C++ online submissions for 3Sum.
 * Memory Usage: 14.7 MB, less than 98.90% of C++ online submissions for 3Sum.
 * 
 * 
 * */
class Solution2
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> solutions;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum > 0)
                {
                    --right;
                }
                else if (sum < 0)
                {
                    ++left;
                }
                else
                {
                    if (right == nums.size() - 1 || nums[left] != nums[left - 1] || nums[right] != nums[right + 1])
                    {
                        solutions.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    }
                    ++left;
                    --right;
                }
            }
        }
        return solutions;
    }
    void print_array(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ", ";
        }
        cout << endl;
    }
};

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
    Solution2 s;
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(input);
    cout << res.size() << endl;
    return 0;
}