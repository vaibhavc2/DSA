// Pair Sum Question: You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
// Note :
// Each pair should be sorted i.e the first value should be less than or equals to the second value.
// Return the list of pairs sorted in non - decreasing order of their first value.In case if two pairs have the same first value, the pair with a smaller second value should come first.

#include "myheader2.h"
#include <set>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    static vector<vector<int>> pairSum(vector<int> &arr, int &target);
    // static vector<set<int>> pairSum(vector<int> &arr, int &target);
    // static vector<pair<int>> pairSum(vector<int> &arr, int &target);
    // static unordered_map<int, int> pairSum(vector<int> &arr, int &target);
};

vector<vector<int>> Solution::pairSum(vector<int> &arr, int &target)
{
    vector<vector<int>> ans;
    set<int> s;
    for (auto &e : arr)
        s.insert(e);

    vector<int> v;
    for (auto e : s)
        v.push_back(e);

    // vector<int>::iterator it = v.begin();
    while (v.front() <= target)
    {
        int top = v.front();
        int x = target - top;
        vector<int> p = {top, x};
        if (binary_search(v.begin(), v.end(), x))
        {
            sort(p.begin(), p.end());
            ans.push_back(p);
            v.erase(v.begin());
            v.erase(Vector::binarySearch_returnIterator(v, x));
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int n, target;
    cin >> n;
    cout << endl;

    Vector::getInput(arr, n);
    cout << endl;
    cout << "target? " << endl;
    cin >> target;

    vector<vector<int>> ans = Solution::pairSum(arr, target);
    for (auto e : ans)
    {
        for (auto i : e)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}