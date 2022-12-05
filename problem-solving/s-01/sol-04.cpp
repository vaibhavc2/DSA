#include <iostream>
#include <vector>
using namespace std;

// Question:
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

class Solution
{
public:
    static vector<int> twoSum(vector<int> &, int);
};

vector<int> Solution::twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size() - i; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {nums[i], nums[j]};
            }
        }
    }
    return {0, 0};
}

int main(int argc, char const *argv[])
{
    int arr_size, target;
    cout << endl;
    cout << "Enter the size of array: ";
    cin >> arr_size;

    vector<int> nums(arr_size);
    cout << endl
         << "Enter the elements in array: " << endl;

    for (int i = 0; i < arr_size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
        cout << endl;
    }

    cout << "Enter the target number: ";
    cin >> target;

    cout << endl;
    vector<int> answer = Solution::twoSum(nums, target);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}