// Q: Peak Index in a Mountain Array (leetcode Q)
// Mountain array: elements increment to reach to a peak (maximum), and then start decreasing

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static int peakIndex_MountainArray(vector<int> &arr);
    static int peakIndex_MountainArray_BetterImplementation(vector<int> &arr);
};

int Solution::peakIndex_MountainArray(vector<int> &arr)
{
    // sort() has time complexity of O(n logn), hence we don't use sort and return the last element
    // linear search or any other methods also have O(n) or higher

    // representation of mountain array:
    //          -
    //       -     -
    //    -           -
    //  -                -

    // hence it is sorted around the peak: start to peak (in ascending order) then peak to end (in descending order)

    int peak = -1;
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    // using Binary Search algorithm to find the peak
    while (start <= end)
    {
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) // condition of peak
        {
            peak = mid;
            break;
        }
        else if (arr[mid] < arr[mid + 1]) // lies in first half array which is increasing
        {
            start = mid + 1;
        }
        else if (arr[mid] > arr[mid + 1]) // lies in second half array which is decreasing
        {
            end = mid; // end = mid - 1; gives error in leetcode, since at some iteration it may happen that mid = 0, then end = -1 if we use mid - 1, hence better to use end = mid, it gives same result
        }
        mid = start + (end - start) / 2;
    }

    return peak;
}

int Solution::peakIndex_MountainArray_BetterImplementation(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    // Better Optimisation of Binary Search Algorithm for this Problem:

    while (s < e) // <= is faltu, no need here
    {
        if (arr[mid] < arr[mid + 1]) // we are on left side of mountain
        {
            s = mid + 1;
        }
        else // we are traversing either right side of mountain, or we are at peak
        {
            e = mid; // mid - 1 can't be done because if mid is on peak, then we skip it!
        }
        mid = s + (e - s) / 2;
    }
    return s; // after the loop the 's' variable gets the index of the peak eventually
}

int main(int argc, char const *argv[])
{
    // vector<int> arr = {0, 1, 2, 3, 2, 1}; // an example of mountain array
    vector<int> arr = {3, 5, 99, 2, 0};
    // 0, 10, 5, 2
    // 0, 2, 1, 0
    // 3, 4, 5, 1

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // int peak = arr[Solution::peakIndex_MountainArray(arr)];
    int peak = arr[Solution::peakIndex_MountainArray_BetterImplementation(arr)];

    cout << "Peak: " << peak << endl;

    return 0;
}