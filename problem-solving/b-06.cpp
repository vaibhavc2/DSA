// CodeStudio, SPOJ Q: Aggressive Cows Problem
// Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int> &stalls, int &k, int &mid)
{
    // have to sort the array of the stalls
    sort(stalls.begin(), stalls.end());

    int cow_count = 1;
    int last_position = 0; // lets fix the last position of one cow at 0

    for (int i = 0; i < stalls.size(); i++)
    {
        // abs() function returns the absolute value of a number, though here abs() is unnecessary because the array 'stalls' has been sorted
        if (abs(stalls[i] - stalls[last_position]) >= mid)
        {
            cow_count++;
            if (cow_count == k)
            {
                return true;
            }
            last_position = i;
        }
    }
    return false;
}

int findMaxOfMinDistance(vector<int> &stalls, int k)
{
    int s = 0;
    int maxi = INT_MIN;
    // int mini = INT_MAX;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
        // mini = min(mini, stalls[i]);
    }
    // int e = maxi - mini;
    int e = maxi;
    // max of stalls can be the max distance... so our search space for solution can be [0, maxi]

    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (isPossibleSolution(stalls, k, mid))
        {
            // agr cows ek distance 'x' pe nhi larengi, to >x pe to kbhi ni larengi, aur hme to vase bhi max distance hi nikalna h
            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // vector<int> stalls = {4, 2, 1, 3, 6};
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4; // no. of cows
    cout << findMaxOfMinDistance(stalls, k) << endl;
    return 0;
}