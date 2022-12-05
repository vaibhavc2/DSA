#include <iostream>
using namespace std;

// swap alternate elements in an array

// void swapArray(int array[], int &size)
// {
//     int a = 0;
//     int b = 1;
//     while (b <= size - 1)
//     {
//         swap(array[a], array[b]);
//         a += 2;
//         b += 2;
//     }
// }

void swapArray(int array[], int &size)
{
    for (int i = 0; i + 1 < size; i += 2)
    {
        swap(array[i], array[i + 1]);
    }
}

int main(int argc, char const *argv[])
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);

    swapArray(array, size);

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}