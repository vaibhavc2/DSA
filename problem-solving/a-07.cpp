#include <iostream>
#include <vector>
using namespace std;

// Q: Find Pivot in a sorted and rotated array

// Try to draw a graphical representation of this array to understand the concept better.

class Solution
{
public:
    static int findPivot(vector<int> &);
    static int findPivot2(vector<int> &); // similar approach, a little difference
};

int Solution::findPivot(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if ((arr[mid - 1] > arr[mid]) && (arr[mid] < arr[mid + 1]))
        {
            break;
        }
        else if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else if (arr[mid] <= arr[0])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return mid;
}

int Solution::findPivot2(vector<int> &arr)
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
    vector<int> arr = {7, 9, 17, 21, 3, 5}; // a sorted and rotated array
    // int pivot_index = Solution::findPivot(arr);
    int pivot_index = Solution::findPivot2(arr);
    cout << "Pivot: " << arr[pivot_index] << endl;
    // cout << arr.size() << " " << arr.capacity() << endl;
    return 0;
}