#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q: Total number of occurrences (frequency) of a given element in an array (or vector)

class Solution
{
public:
    static int frequency_BinarySearch(vector<int> &, int &);
};

// Here, Binary Search is the Best Method because of it's worst case time complexity O(logn). Other methods have O(n) or higher!

int Solution::frequency_BinarySearch(vector<int> &arr, int &k)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start - (start - end) / 2;

    int first = 0;
    int last = 0;

    if (!(binary_search(arr.begin(), arr.end(), k)))
    {
        return 0;
    }

    // finding first occurrence
    while (start <= end)
    {
        if (arr[mid] == k)
        {
            first = mid;
            end = mid - 1; // since first occurrence will be in left!
        }
        else if (k > arr[mid])
        {
            start = mid + 1; // look in the right
        }
        else // k < arr[mid]
        {
            end = mid - 1; // look in the left
        }
        mid = start - (start - end) / 2;
    }

    // finding last occurrence
    start = first; // we know first occurrence
    end = arr.size() - 1;
    mid = start - (start - end) / 2;
    while (start <= end)
    {
        if (k == arr[mid])
        {
            last = mid;
            start = mid + 1;
        }
        else if (k < arr[mid])
        {
            end = mid - 1;
        }
        // else // k > arr[mid]
        // {} // this condition will never be possible because of sorted array!

        mid = start - (start - end) / 2;
    }

    int frequency = last - first + 1;

    return frequency;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << endl;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << endl;

    sort(arr.begin(), arr.end());

    int key;
    cout << endl;
    cout << "Key? ";
    cin >> key;
    cout << endl;

    cout << "Total Number of occurrences of the given element in the array: " << Solution::frequency_BinarySearch(arr, key) << endl;

    return 0;
}