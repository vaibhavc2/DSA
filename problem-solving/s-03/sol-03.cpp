#include <iostream>
#include <vector>
#include <numeric> // for accumulate() function
using namespace std;

// Q: Given an array of integers arr, return true if we can partition the array into three non-empty parts with equal sums.

// using 2 pointer approach
// solution for O(n)

// Following 2 pointer approach does not work! Starting from middle point, we miss many test cases!
// bool canThreePartsEqualSum(vector<int> &arr)
// {
//     int n = arr.size();
//     if (n < 3)
//     {
//         return 0;
//     }

//     int left_sum = 0;
//     int right_sum = 0;

//     int s = 0;
//     int e = n - 1;
//     int mid = s + (e - s) / 2;

//     while (s < mid)
//     {
//         left_sum += arr[s];
//         s++;
//     }
//     s--;
//     while (e > mid)
//     {
//         right_sum += arr[e];
//         e--;
//     }
//     e++;

//     int middle_sum = arr[mid];
//     int counter = 0;

//     while (s > 0 || e < n - 1)
//     {
//         if (left_sum == middle_sum && middle_sum == right_sum)
//             return 1;

//         // if (s == 1 && e == n - 2)
//         //     return 0;

//         if ((s > 0) && (counter % 2 == 0))
//         {
//             left_sum -= arr[s];
//             middle_sum += arr[s];
//             s--;
//         }
//         if ((e < n - 1) && (counter % 2 != 0))
//         {
//             right_sum -= arr[e];
//             middle_sum += arr[e];
//             e++;
//         }
//         counter++;
//     }
//     return 0;
// }

// Approach and Logic: calculate total of all elements in the array. Check if it is divisible by 3 because if not, then the array can't be divided into 3 parts such that sums are equal. Next, calculate req. target sum, and count how many times does it cross that target. Finally return true if it crosses the req. target 3 or more than 3 times.

bool canThreePartsEqualSum(vector<int> &arr)
{
    // accumulate() is used to find sum, 0 is initial value of sum
    int total = accumulate(arr.begin(), arr.end(), 0);
    if (total % 3 != 0)
        return false;
    int required_target = total / 3;
    int sum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == required_target)
        {
            count++;
            sum = 0;
        }
    }
    return (count >= 3); // > because in case of required_target=0
}

int main(int argc, char const *argv[])
{
    // vector<int> arr = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    // vector<int> arr = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
    // vector<int> arr = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    vector<int> arr = {1, -1, 1, -1, 1, -1, 1, -1};
    // vector<int> arr = {1, -1, 1, -1};
    if (canThreePartsEqualSum(arr))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}