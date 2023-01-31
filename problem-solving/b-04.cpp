// Book Allocation Problem: CodeStudio
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
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    static int allocateBooks(vector<int> &books, int &m);
};

bool isPossibleSolution(vector<int> &books, int &mid, int &m)
{
    // vector<int> students;
    int student_count = 1;
    int page_sum = 0;

    for (int i = 0; i < books.size(); i++)
    {
        // int count = 0;
        if ((page_sum + books[i]) <= mid)
        {
            page_sum += books[i];
            // count++;
        }
        else
        {
            // if (count != 0)
            // students.push_back(page_sum);
            student_count++;
            if (student_count > m || books[i] > mid)
            {
                return false;
            }

            page_sum = books[i];
        }
    }
    // students.push_back(page_sum);
    // student_count++;

    // if (student_count == m)
    // {
    //     return true;
    // }

    return true;
}

int Solution::allocateBooks(vector<int> &books, int &m) // m: number of students
{
    // assume min to be 0, though not a possible case, but binary search algorithm will ignore it successfully
    int start = 0;
    int end = accumulate(books.begin(), books.end(), 0);
    // calculate total here, and assume it as the end (max)

    int mid = start + (end - start) / 2;
    int ans = -1;
    // using Binary Search Algorithm:
    while (start <= end)
    {
        if (isPossibleSolution(books, mid, m))
        {
            ans = mid;
            end = mid - 1; // move to left because we want min. solution
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // vector<int> books = {5, 17, 100, 11};
    vector<int> books = {12, 34, 67, 90};
    // vector<int> books = {10, 20, 30, 40};
    // vector<int> books = {25, 46, 28, 49, 24};
    int m = 2;

    cout << Solution::allocateBooks(books, m) << endl;
    return 0;
}