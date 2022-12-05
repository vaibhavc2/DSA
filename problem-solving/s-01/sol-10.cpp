// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
// You must write an algorithm that runs in O(n) time and uses only constant extra space.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    unordered_map<int, int> freqmap;
    vector<int> ans;

    for (auto &e : nums)
    {
        freqmap[e]++;
    }

    for (auto x : freqmap)
    {
        if (x.second == 2) // condition is for elements appearing twice, & all elements appear only once or twice
        {
            ans.push_back(x.first);
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    int n;
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<int> ans = findDuplicates(v);

    cout << endl;
    cout << endl;

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}