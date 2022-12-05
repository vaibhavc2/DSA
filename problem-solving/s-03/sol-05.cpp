// So when to use Binary Search?
// When we can get a search space in a sorted array and we can neglect the left or right part by seeing if the solution is possible

// CodeStudio Q: Painter's Partition Problem

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool isPossibleSolution(vector<int> &boards, int &k, int &mid)
{
    int painter_count = 1;
    int time_sum = 0;

    for (int i = 0; i < boards.size(); i++)
    {
        if (time_sum + boards[i] <= mid)
        {
            time_sum += boards[i];
        }
        else
        {
            painter_count++;
            if (painter_count > k || boards[i] > mid)
            {
                return false;
            }
            time_sum = boards[i];
        }
    }
    return true;
}

int findMinOfMaxTime(vector<int> &boards, int k)
{
    int s = 0;
    int e = accumulate(boards.begin(), boards.end(), 0);
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (isPossibleSolution(boards, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    // vector<int> boards = {10, 20, 30, 40};
    // vector<int> boards = {5, 5, 5, 5};
    vector<int> boards = {48, 90};
    int k = 2; // no. of painters
    cout << findMinOfMaxTime(boards, k) << endl;
    return 0;
}