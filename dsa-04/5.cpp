#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Built-in algorithms and how to use them

int main(int argc, char const *argv[])
{
    vector<int> arr;

    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(4);
    arr.push_back(9);
    arr.push_back(3);

    int n = 0;

    cout << "Enter number: ";
    cin >> n;

    arr.shrink_to_fit();

    // sort function is based on introsort i.e. combination of quick sort, heap sort and insertion sort

    // sort() has time complexity of O(nlog(n))

    sort(arr.begin(), arr.end()); // ascending order
    // sort(arr.begin(), arr.end(), greater<int>()); // descending order

    // binary search works only if the array is sorted in ascending order!

    bool element_present = binary_search(arr.begin(), arr.end(), n);

    cout << endl;

    if (element_present)
    {
        cout << "Yes, it is present in the array!" << endl;
    }
    else
    {
        cout << "False! This number is not present in the array." << endl;
    }

    for (vector<int>::iterator itr = arr.begin(); itr != arr.end(); itr++)
        cout << *itr << " ";
    cout << endl;

    cout << "Lower Bound : " << lower_bound(arr.begin(), arr.end(), n) - arr.begin() << endl;
    cout << "Upper Bound : " << upper_bound(arr.begin(), arr.end(), n) - arr.begin() << endl;

    rotate(arr.begin(), arr.begin() + 1, arr.end());
    cout << "After Rotate: " << endl;
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}