#include <iostream>
using namespace std;

// Q1: Array contains 0s & 1s. Return sorted array. Try time complexity O(n) or lesser.
// Q2: Array contains 0s, 1s or 2s. Return sorted array. Try time complexity O(n) or lesser.

void sort01(int *arr, int n)
{
    int i = 0;
    int j = n - 1;
    // this approach is called two-pointer approach & is quite efficient than other methods sometimes, here it is better than sort() because sort() has O(nlogn)
    while (i < j)
    {
        if (arr[i] == 0)
        {
            i++;
        }
        else if (arr[j] == 1)
        {
            j--;
        }
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

void sort012(int *arr, int n)
{ // 3 pointer approach
    int i = 0;
    int s = 0;
    int e = n - 1;

    while (i <= e)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[s]);
            i++;
            s++;
        }
        else if (arr[i] == 1)
        {
            i++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[e]);
            e--;
        }
    }
}

int main(int argc, char const *argv[])
{
    // int *arr = new int[10];

    // int arr1[15] = {1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1};
    // sort01(arr1, 15);

    // for (int i = 0; i < 15; i++)
    // {
    //     cout << arr1[i] << " ";
    // }
    // cout << endl;

    int arr2[10] = {2, 1, 0, 0, 2, 1, 2, 0, 1, 2};
    sort012(arr2, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}