#include <iostream>
using namespace std;

void reverseArray(int arr[], int &size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int a = arr[i];
        int b = arr[size - (i + 1)];
        arr[size - (i + 1)] = a;
        arr[i] = b;
    }
}

// Approach @2: another way to reverse

void reverseArray2(int arr[], int &size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 8, -1, 0, 34, 2, -67, 4, 6, -92, 23};
    int size = sizeof(arr) / sizeof(arr[0]);
    reverseArray2(arr, size);
    cout << "size = " << size << endl
         << "Reverse Array = ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}