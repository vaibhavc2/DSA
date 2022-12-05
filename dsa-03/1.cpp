#include <iostream>
using namespace std;

// array is always passed through reference, no matter which way you use!

class ArrayMethods
{
public:
    static void inputArray(int *, int &size);
    static void printArray(int (&array)[], int &size);
    static int minimumValue(int[], int &size);
    static int maximumValue(int[], int &size);
    static int sumOfArr(int *, int &size);
};

void ArrayMethods::inputArray(int *array, int &size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": " << endl;
        cin >> array[i];
    }
}

void ArrayMethods::printArray(int (&array)[], int &size)
{
    cout << "\nPrinting the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

int ArrayMethods::minimumValue(int array[], int &size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

int ArrayMethods::maximumValue(int array[], int &size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

int ArrayMethods::sumOfArr(int *arr, int &size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    // int *array = new int[100]();
    int array[100];
    fill_n(array, 100, 0); // intialize array to 0

    int size = 0;
    // int size = sizeof(array)/sizeof(array[0]);
    // int size = sizeof(array)/sizeof(int);
    cout << "Enter size of array" << endl;
    cin >> size;
    cout << endl;

    ArrayMethods::inputArray(array, size);
    ArrayMethods::printArray(array, size);

    cout << endl
         << endl
         << "Minimum value: " << ArrayMethods::minimumValue(array, size) << endl;
    cout << "Maximum value: " << ArrayMethods::maximumValue(array, size) << endl;
    cout << "Sum of array: " << ArrayMethods::sumOfArr(array, size) << endl;
    return 0;
}