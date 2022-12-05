#include "myheader.h"
// Insertion sort
// It is a Stable sorting algorithm
// Best case time complexity: O(n)
// Worst case time complexity: O(pow(n,2))
// Average case time complexity: O(pow(n,2))
// Space complexity: O(1)

void insertionSort(vector<int> &arr)
{
    // we assume that i = 0 is sorted array and start sorting from i = 1, after that in every iteration, size of sorted array increases by 1 from left towards right.
    int i = 1;
    int j;
    while (i < arr.size())
    {
        j = i - 1;
        int temp = arr[i];
        // iski value ko store kralia, ab 'j' ke elements ko one by one shift krte jao jb tk 'j' wale bare hai iski value se

        while (j >= 0)
        {
            // we dont swap, rather shift the elements as needed and insert element at the right place to make the left part of array till 'i' as sorted

            if (arr[j] > temp)
            {
                // shift kro
                arr[j + 1] = arr[j];
            }
            else // temp > arr[j]
                // ruk jao, iske piche jane ka need nhi h, vo to sorted hi hai to baki sb bhi 'temp' wali value se chhote hi honge agr koi ek mil gya hai to
                break;

            j--;
        }

        arr[j + 1] = temp;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int n, target;
    cin >> n;
    cout << endl;

    Vector::getInput(arr, n);
    insertionSort(arr);
    Vector::print(arr);

    return 0;
}