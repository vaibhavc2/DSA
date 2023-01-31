#include "myheader.h"

// Q: To find an element in a sorted and rotated array

class Solution
{
public:
    static int findPivot(vector<int> &);
};

int Solution::findPivot(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] >= arr[0]) // i.e. mid lies on upper line
        {
            start = mid + 1;
        }
        else // if (arr[mid] < arr[0]) i.e. mid lies on lower line
        {
            end = mid; // not: end = mid-1 because mid might be on the pivot
        }
        mid = start + (end - start) / 2;
    }

    return start;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {18, 23, 67, 99, 5, 7, 15}; // a sorted and rotated array

    int pivot_index = Solution::findPivot(arr);
    int pivot = arr[pivot_index];

    int key;
    cin >> key;
    cout << endl;

    if (key == pivot)
    {
        cout << pivot_index << endl;
    }
    else
    {
        vector<int> new_arr;
        int index = 0;

        vector<int>::iterator pivot_itr = arr.begin() + pivot_index;
        // OR
        // vector<int>::iterator pivot_itr = arr.begin();
        // advance(pivot_itr, pivot_index);
        if (key >= *(arr.begin())) // lies on upper line
        {
            // Copying vector by insert function
            new_arr.insert(new_arr.begin(), arr.begin(), pivot_itr);
            index = Vector::binarySearch_returnIndex(new_arr, key);
        }
        else // lies on lower line....
        {
            // Copying vector using assign function
            new_arr.assign(pivot_itr, arr.end());
            index = pivot_index + Vector::binarySearch_returnIndex(new_arr, key);
        }
        cout << index << endl;
    }

    return 0;
}