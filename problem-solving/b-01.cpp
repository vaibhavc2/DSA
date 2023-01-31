// Leetcode Question:
// Find Pivot Index of an array: The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static int pivotIndex(vector<int> &nums);
};

int sumOfArray(vector<int> &arr, int start, int end)
{
    int sum = 0;
    // for (auto &e : arr)
    // {
    //     sum += e;
    // }
    if (end < 0 || start > end)
    {
        return sum; // return 0 in this case
    }

    for (int i = start; i <= end; i++)
    {
        sum += arr[i];
    }

    return sum;
}

// The mid-index approach fails some test-cases because array is not sorted and also includes negative integers.
// int Solution::pivotIndex(vector<int> &nums)
// {
//     int s = 0;
//     int e = nums.size() - 1;
//     int i = s + (e - s) / 2; // start index 'i' from mid

//     while (i >= s && i <= e)
//     {
//         int left_sum = sumOfArray(nums, s, i - 1);
//         int right_sum = sumOfArray(nums, i + 1, e);
//         if (left_sum == right_sum)
//         {
//             return i;
//         }
//         if (left_sum < right_sum)
//         {
//             if (i == s)
//             {
//                 break;
//             }
//             i++;
//         }
//         else // left_sum > right_sum
//         {
//             if (i == e)
//             {
//                 break;
//             }
//             i--;
//         }
//     }
//     return -1;
// }

// The following solution is correct but gives TLE (Time Limit Exceeded). Therefore we need to optimise the solution for better time complexity
// int Solution::pivotIndex(vector<int> &nums)
// {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int left_sum = sumOfArray(nums, 0, i - 1);
//         int right_sum = sumOfArray(nums, i + 1, nums.size() - 1);
//         if (left_sum == right_sum)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// Optimised solution: O(n)
int Solution::pivotIndex(vector<int> &nums)
{
    if (nums.size() == 0)
        return -1;
    int leftSum = 0, rightSum = 0;
    for (int num : nums)
        rightSum += num;

    for (int i = 0; i < nums.size(); i++)
    {
        rightSum -= nums[i];
        if (rightSum == leftSum)
            return i;
        leftSum += nums[i];
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

    int pivot_index = Solution::pivotIndex(nums);
    if (pivot_index != -1)
    {
        cout << "The pivot element is " << nums[pivot_index] << ".\nIt's index: " << pivot_index << endl;
    }
    else
    {
        cout << "There is no pivot element present." << endl;
    }

    return 0;
}