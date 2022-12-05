#include <iostream>
using namespace std;

// Questions:
// Q1 You have been given an integer array/list(ARR) of size N. Where N is equal to 2M + 1. Now, in the given array / list, 'M' numbers are present twice and one number is present only once.You need to find and return that number which is unique in the array / list.
// Find Duplicate number in the array. (here we use brute force, but next we will do question for a better approach.)

class ArrayMethods
{
public:
    // static int findUnique(int[], int &);
    static int findUnique2(int[], int &);
    static int findDuplicate(int[], int &);
    static int findElements(int[], int &, int);
};

// int ArrayMethods::findUnique(int arr[], int &size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (ArrayMethods::findElements(arr, size, arr[i]) == 1)
//         {
//             return arr[i];
//         }
//     }
//     return INT_MIN;
// }

// More efficient and better implementation using XOR
int ArrayMethods::findUnique2(int arr[], int &size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    // ^ - XOR
    // a ^ a = 0 & 0 ^ a = a
    // arr[0] ^ arr[1] ^ arr[2] ^ arr[3] ......  : using the above 2 formulas solving this will always give just the unique element as its final answer
    return ans;
}

int ArrayMethods::findDuplicate(int arr[], int &size)
{
    for (int i = 0; i < size; i++)
    {
        if (ArrayMethods::findElements(arr, size, arr[i]) == 2)
        {
            return arr[i];
        }
    }
    return INT_MIN;
}

int ArrayMethods::findElements(int arr[], int &size, int key)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            count++;
    }
    return count;
}

int main()
{
    // int array1[] = {0, 1, 7, 9, 0, 3, 3, 1, 9};
    int array1[] = {1, 2, 3, 2, 1};

    int array1_size = sizeof(array1) / sizeof(array1[0]);

    // if (ArrayMethods::findUnique(array1, array1_size) != INT_MIN)
    //     cout << "Unique element in the array1: " << ArrayMethods::findUnique(array1, array1_size) << endl;
    cout << "Unique element in the array1: " << ArrayMethods::findUnique2(array1, array1_size) << endl;

    int array2[] = {0, 1, 2, 3, 4, 5, 2, 9, 51};
    int array2_size = sizeof(array2) / sizeof(array2[0]);

    if (ArrayMethods::findDuplicate(array2, array2_size) != INT_MIN)
        cout << "Duplicate element in the array2: " << ArrayMethods::findDuplicate(array2, array2_size) << endl;

    return 0;
}