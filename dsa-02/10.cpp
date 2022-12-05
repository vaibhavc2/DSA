// We can initialize the array with any value by using the fill_n command

#include <iostream>
using namespace std;

int sumArr(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int array[100];

    // To initialize the array with value'1'.
    fill_n(array, 100, 1);

    // To check the array input (kewaal 5 hi kari h print)
    for (int i = 0; i <= 5; i++)
    {
        cout << array[i] << endl;
    }

    int a[100], n;
    // Taking the size of the array
    cin >> n;
    // Taking the array from the user
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "The sum of all the elements in the array is: " << sumArr(a, n) << endl;
}