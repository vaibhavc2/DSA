#include "myheader.h"

// Bubble Sort
// for every ith round/iteration, bubble sort keeps placing the greatest ith integer on the right.
// Worst-case Time complexity: O(pow(n,2));
// Best-case Time complexity: O(n);
// Worst-case Time complexity: O(pow(n,2));
// Space Complexity: O(1)
// It is a stable sorting algorithm

// It is an adaptive algo, it takes into account those numbers already sorted in the array.

void bubbleSort(vector<int> &arr)
{
    // for round 1 to n-1 :: here n=size
    for (int i = 1; i < arr.size(); i++)
    {
        bool check_swap = false;
        // process all elements till n-i-1 index for each iteration of i from above
        for (int j = 0; j < arr.size() - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                check_swap = true;
                // this is optimising the algorithm, if not even a single time, swap() is performed, then the array has been sorted in the iteration and we don't need to do further iterations
            }
        }
        if (check_swap == false)
        {
            // at this point the array is already sorted
            break;
        }
    }

    // below can also be implemented in the same way as above, just main loop is from i=0 to n-1, hence inner loop is from 0 to n-i-1

    // for (int i = 0; i < arr.size() - 1; i++)
    // {
    //     for (int j = 0; j < arr.size() - i - 1; j++)
    //     {
    //         if (arr[j] > arr[j + 1])
    //         {
    //             swap(arr[j], arr[j + 1]);
    //         }
    //     }
    // }
}

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int n;
    cin >> n;
    Vector::getInput(arr, n);

    bubbleSort(arr);

    Vector::print(arr);

    return 0;
}