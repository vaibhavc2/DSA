#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Question:
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.

class Solution
{
public:
    bool static uniqueOccurrences_bruteForce(vector<int> &);
    bool static uniqueOccurrences_better(vector<int> &);
    bool static uniqueOccurrences_best(vector<int> &);
};

bool Solution::uniqueOccurrences_bruteForce(vector<int> &arr)
{
    vector<int> ans;
    int size = arr.size();
    int i = 0;
    sort(arr.begin(), arr.end());
    while (i < size)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        ans.push_back(count);
        i = i + count;
    }
    size = ans.size();
    sort(ans.begin(), ans.end());
    for (int i = 0; i < size - 1; i++)
    {
        if (ans[i] == ans[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool Solution::uniqueOccurrences_better(vector<int> &arr)
{
    unordered_map<int, int> freqmap;
    vector<int> freqvect;

    // using maps in C++ is basically a Hash Table
    // This technique for solving problems is called Hashing
    // store {number:frequency} in freqmap
    for (int i = 0; i < arr.size(); i++)
    {
        freqmap[arr[i]]++; // stores number in first, and its freq. in second
    }
    // store frequencies in vector
    for (auto i : freqmap)
    {
        cout << i.first << " " << i.second << endl;
        freqvect.push_back(i.second);
    }
    // sort vector
    sort(freqvect.begin(), freqvect.end());

    // if any value matches with next value, frequencies aren't unique.
    for (int i = 0; i < freqvect.size() - 1; i++)
    {
        if (freqvect[i] == freqvect[i + 1])
        {
            return false;
        }
    }

    return true;
}

bool Solution::uniqueOccurrences_best(vector<int> &arr)
{
    unordered_map<int, int> freqmap;

    for (auto &e : arr) //&e is used bcz arr is also reference....
    {
        freqmap[e]++; // store number in first, and store freq in second for each element of the vector array
    }

    unordered_set<int> freq;

    for (auto x : freqmap)
    {
        freq.insert(x.second);
    }

    if (freq.size() == freqmap.size())
    {
        // because set stores only unique elements, if duplicate frequencies are present the size will differ!!
        return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v_array;
    v_array.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        v_array.push_back(e);
    }

    // if (Solution::uniqueOccurrences_bruteForce(v_array))
    //     cout << "true" << endl;
    // else
    //     cout << "false" << endl;
    // if (Solution::uniqueOccurrences_better(v_array))
    //     cout << "true" << endl;
    // else
    //     cout << "false" << endl;
    if (Solution::uniqueOccurrences_best(v_array))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}