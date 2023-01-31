#include <bits/stdc++.h>
using namespace std;

// Q: get Winner from an array of Votes, if 2 or more winners, return lexicographically smaller element as answer

string getWinner(vector<string> &votes)
{
    // Write your code here.
    // unordered_map<string, int> freqmap_votes;
    string ans;
    unordered_map<string, int> freqmap_votes;
    for (auto &itr : votes)
    {
        freqmap_votes[itr]++;
    }
    int maxi = INT_MIN;
    for (auto e : freqmap_votes)
    {
        maxi = max(e.second, maxi);
    }
    int count = 0;
    for (auto e : freqmap_votes)
    {
        if (e.second == maxi)
        {
            ans = e.first;
            count++;
        }
    }
    if (count > 1)
    {
        // lexicographically smallest element:
        auto itr = min_element(freqmap_votes.begin(), freqmap_votes.end());
        ans = itr->first;
    }
    return ans;
    // auto itr = freqmap_votes.end();
    // return freqmap_votes.begin()->first;
    // auto itr = max_element(freqmap_votes.begin(), freqmap_votes.end());
    // return itr->first;
}

// Similar approach but a little more efficient, but works only if tie can be in two "strings"
// void findWinner(vector<string> &votes)
// {

//     // Insert all votes in a hashmap
//     unordered_map<string, int> mapObj;
//     for (auto &str : votes)
//     {
//         mapObj[str]++;
//     }

//     // Traverse through map to find the candidate
//     // with maximum votes.
//     int maxValueInMap = 0;
//     string winner;
//     for (auto &entry : mapObj)
//     {
//         string key = entry.first;
//         int val = entry.second;
//         if (val > maxValueInMap)
//         {
//             maxValueInMap = val;
//             winner = key;
//         }

//         // If there is a tie, pick lexicographically
//         // smaller.
//         else if (val == maxValueInMap && winner > key)
//             winner = key;
//     }
//     cout << winner << endl;
// }

int main()
{
    // vector<string> votes = {"Rahul", "Ankur"};
    // vector<string> votes = {"John", "Tim", "Marry", "John"};
    vector<string> votes = {"Shubham", "Atul", "Biden", "Priya", "Lincoln", "Ankit", "Neeti", "Arya", "Ekta", "Amit", "Shubham"};
    cout << getWinner(votes) << endl;
    return 0;
}