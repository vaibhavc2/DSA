#include <iostream>
using namespace std;

// Default argument in a function

// default args all must lie on the right-most side in a function declaration
// void print(int* arr, int start = 0,  int size); // this is NOT VALID


// Here, By default, 'start' will take '0' as the value, but we can give any value to be taken as the default value for that parameter
void print(int* arr, int size, int start = 0)
{
    for (int i = start; i < size; i++)
    {
        cout << *(arr + i) << " ";
        // cout << arr[i] << " ";
        // cout << i[arr] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    print(arr, size); // now it is optional to pass 'start' argument
    print(arr, size, 2); // here, it overrides the 'start' value as '2'
    return 0;
}