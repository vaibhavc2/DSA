// You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.
// 1. The length of each array is greater than zero.
// 2. Both the arrays are sorted in non—decreasing order.
// 3. The output should be in the order of elements that occur arrays.
// 4. If there is no intersection present then return a single in the original integer '-1'

// #include <iostream>
// #include <vector>
#include <algorithm>
#include <set>
// using namespace std;
#include "myheader.h"

void setInsertion(vector<int> &v, set<int> &s)
{
    for (auto &e : v)
        s.insert(e);
}

class Solution
{
public:
    static vector<int> arrayIntersection(vector<int> &arr1, vector<int> &arr2);
};

vector<int> Solution::arrayIntersection(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> ans;
    set<int> s1;
    set<int> s2;
    // we use sets to get arrays of unique elements only, and also in sorted manner
    setInsertion(arr1, s1);
    setInsertion(arr2, s2);

    int n = s1.size();
    int m = s2.size();

    if (n < m)
    {
        for (auto x : s1)
        {
            if (binary_search(s2.begin(), s2.end(), x))
            {
                ans.push_back(x);
            }
        }
    }
    else
    {
        for (auto x : s2)
        {
            if (binary_search(s1.begin(), s1.end(), x))
            {
                ans.push_back(x);
            }
        }
    }

    if (ans.size() == 0)
    {
        ans.push_back(-1);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n, m;
    vector<int> arr1, arr2;
    cout << "Enter size of array-1: ";
    cin >> n;
    // vector<int> arr1(n); // this shouldn't be used here since it makes vector of capacity & size n and initializes all elements to 0, therefore when we push_back into vector, new elements are added! So NOT GOOD PRACTICE

    cout << "Enter elements in array-1: " << endl;
    Vector::getInput(arr1, n);

    cout << endl;
    cout << "Enter size of array-2: ";
    cin >> m;
    // vector<int> arr2(m); // this shouldn't be used since it makes vector of capacity & size n and initializes all elements to 0, therefore when we push_back into vector, new elements are added! So NOT GOOD PRACTICE

    cout << "Enter elements in array-2: " << endl;
    Vector::getInput(arr2, m);

    // sort(arr1.begin(), arr1.end());
    // sort(arr2.begin(), arr2.end());

    vector<int> ans = Solution::arrayIntersection(arr1, arr2);

    cout << endl
         << "Intersection Array: " << endl;
    Vector::print(ans);

    return 0;
}