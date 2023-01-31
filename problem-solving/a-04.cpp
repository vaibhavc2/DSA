// You have been given a sorted array / list ARR consisting of 'N' elements.You are also given an integer 'K'. Now, your task is to find the first and last occurrence of 'K' in ARR.
// If 'K' is not present in the array, then the first and the last occurrence will be - 1.
// ARR may contain duplicate elements.

#include <iostream>
#include <vector>
// #include "myheader.h"
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static pair<int, int> firstAndLastPosition(vector<int> &, int);
    static pair<int, int> firstAndLastPosition_BetterApproach(vector<int> &, int);
};

// this is not a good approach, gives TLE !!
// pair<int, int> Solution::firstAndLastPosition(vector<int> &arr, int k)
// {
//     pair<int, int> ans;
//     // this is to return (-1, -1) if 'k' is not present
//     if (!(binary_search(arr.begin(), arr.end(), k)))
//     {
//         ans.first = -1;
//         ans.second = -1;
//         return ans;
//     }

//     // int n = arr.size();
//     unordered_map<int, int> freqmap;

//     // storing freq in freqmap:
//     for (auto e : arr)
//     {
//         // sorted array, hence we store only till 'k'
//         if (e > k)
//         {
//             break;
//         }
//         freqmap[e]++;
//     }

//     vector<int> v;
//     int start_index = 0;
//     int k_freq = 0;

//     // unordered_map<int, int>::iterator itr = freqmap.begin();
//     for (auto i : freqmap)
//     {
//         if (i.first != k)
//         {
//             start_index += i.second;
//         }
//         if (i.first == k)
//         {
//             k_freq = i.second;
//         }
//     }
//     int end_index = start_index + (k_freq - 1);
//     ans.first = start_index;
//     ans.second = end_index;

//     return ans;
// }

pair<int, int> Solution::firstAndLastPosition_BetterApproach(vector<int> &arr, int k)
{
    // we use Binary Search to optimise the solution
    pair<int, int> ans;

    int start = 0;
    int end = arr.size() - 1;
    int mid = start - (start - end) / 2;

    int first = 0;
    int last = 0;

    if (!(binary_search(arr.begin(), arr.end(), k)))
    {
        first = -1;
        last = -1;
        ans.first = first;
        ans.second = last;
        return ans;
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

    ans.first = first;
    ans.second = last;

    return ans;
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

    // print sorted array:
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    int key;
    cout << endl;
    cout << "Key? ";
    cin >> key;
    cout << endl;

    // pair<int, int> ans = Solution::firstAndLastPosition(arr, key);
    pair<int, int> ans = Solution::firstAndLastPosition_BetterApproach(arr, key);

    cout << endl
         << "Indices: " << ans.first << " " << ans.second << endl;

    return 0;
}