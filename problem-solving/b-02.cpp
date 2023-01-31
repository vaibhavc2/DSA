#include <iostream>
#include <vector>
using namespace std;

// Pivot-Index Q variation of statement:
// Leetcode Q: Find the Middle Index of Array
// https://leetcode.com/problems/find-the-middle-index-in-array/

int findMiddleIndex(vector<int> &nums)
{
    int right_sum = 0;
    int left_sum = 0;
    if (nums.size() == 0)
        return -1;

    for (auto num : nums)
        right_sum += num;

    for (int i = 0; i < nums.size(); i++)
    {
        right_sum -= nums[i];
        if (left_sum == right_sum)
        {
            return i;
        }
        left_sum += nums[i];
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << endl
         << "Enter the elements in the array: " << endl;

    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;
        nums.push_back(n);
    }
    cout << endl;

    int middle_index = findMiddleIndex(nums);
    if (middle_index != -1)
    {
        cout << "The middle-index element is " << nums[middle_index] << ".\nIt's index: " << middle_index << endl;
    }
    else
    {
        cout << "There is no middle-index element present." << endl;
    }

    return 0;
}