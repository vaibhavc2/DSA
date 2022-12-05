#include <iostream>
using namespace std;

// Linear search
class ArraySearch
{
public:
    static bool linearSearch(int[], int &, int &);
};

bool ArraySearch::linearSearch(int arr[], int &size, int &key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 2, 6, 9, -5, 7, 1, 2, -11, 99, 45, -7, 0};
    int size = (sizeof(arr) / sizeof(int));
    int key = -11;

    if (ArraySearch::linearSearch(arr, size, key))
        cout << "Element found in the array " << endl;
    else
        cout << "Element NOT found in the array " << endl;

    return 0;
}
