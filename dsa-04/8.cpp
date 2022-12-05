// #include <iostream>
// #include <vector>
// using namespace std;
#include "myheader.h"

// Selection Sort
// This algorithm is useful when the array is small in length.
// Worst-case Time Complexity: O(pow(n,2))
// Best-case Time Complexity: O(pow(n,2))
// Average-case Time Complexity: O(pow(n,2))
// Space Complexity: O(1)
// By default, it is an UNSTABLE sorting algorithm.
// Stable sorting algorithm doesnot change the order of same values
// UnStable sorting changes the order of same values while sorting

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int n, target;
    cin >> n;
    cout << endl;

    Vector::getInput(arr, n);
    selectionSort(arr);
    Vector::print(arr);

    return 0;
}