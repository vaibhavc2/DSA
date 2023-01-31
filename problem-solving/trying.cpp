#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Book Allocation Problem: CodeStudio (self-trying)
// Given an array ‘arr’ of integer numbers . where ‘arr[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students and the task is to allocate all the books to their students. Allocate books in such a way that:
// 1. Each student gets at least one book.
// 2. Each book should be allocated to a student.
// 3. Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

// Constraints:
// 1 <= T <= 50
// 2 <= M <= N <= 10 ^ 3
// 1 <= A[i] <= 10 ^ 9
// Sum of all A[i] do not more than 10 ^ 9.

class Solution
{
public:
    static int allocateBooks(vector<int> &arr, int &n, int &m);
};

int Solution::allocateBooks(vector<int> &arr, int &n, int &m)
{
    // n is arr.size()

    if (!(m <= n && m > 0))
    {
        return -1;
    }
    int ans = 0;

    if (m == 1)
    {
        // return sum of array (represents the total number of pages)
        for (int i = 0; i < arr.size(); i++)
        {
            ans += arr[i];
        }
        return ans;
    }

    if (n == m)
    {
        // return max number of pages
        auto itr = max_element(arr.begin(), arr.end()); // built-in function that returns an iterator pointing to the max element in the array, O(n) complexity just like if we made a custom function using loop
        ans = *itr;
        return ans;
    }

    return ans;
}