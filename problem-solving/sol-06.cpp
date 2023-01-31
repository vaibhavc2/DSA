#include <iostream>
using namespace std;

// Given an array of integers arr , return true if each value in the array is unique or false otherwise.

class Solution
{
public:
    static bool allUnique(int *, int &);
    static int findElements(int *, int &, int &);
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

int Solution::findElements(int *arr, int &size, int &key)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 0};
    int size = sizeof(arr) / sizeof(int);

    if (Solution::allUnique(arr, size))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}