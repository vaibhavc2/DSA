// Given an array of integers arr , return true if the number of occurrences of each value in the array is unique or false otherwise.

#include <iostream>
using namespace std;

class Solution
{
public:
    static bool allUnique(int *, int &);
    static int findElements(int *, int &, int);
    static bool allUniqueOccurrences(int *, int &);
};

bool Solution::allUnique(int *arr, int &size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        if (findElements(arr, size, arr[i]) != 1)
        {
            return false;
        }
    }
    return true;
}

int Solution::findElements(int *arr, int &size, int key)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            count++;
    }
    return count;
}

bool Solution::allUniqueOccurrences(int *arr, int &size)
{
    int count = 0;
    int occurrences[100] = {0};
    int m = size;
    for (; count < m; count++)
    {
        occurrences[count] = findElements(arr, size, arr[count]);
        m -= (occurrences[count] - 1);
    }

    if (allUnique(occurrences, count))
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    // int arr[] = {1, 2, 3, 0, 3, 3, 1, 0, 0};
    // int arr[] = {1, 2, 3, 0, 3, 3, 1, 0, 0, 0};
    // int arr[] = {1, 2, 2, 1, 1, 3, 3};
    int arr[] = {1, 2, 2, 1, 1, 3};
    // int arr[] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    int size = sizeof(arr) / sizeof(int);

    if (Solution::allUniqueOccurrences(arr, size))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}