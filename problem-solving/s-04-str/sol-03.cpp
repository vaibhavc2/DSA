#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

// Leetcode Q: Reverse Words in a String II
// Given an input string, reverse the string word by word.

// Example:
// Input:
// ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
// Output:
// ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
// Note:
// A word is defined as a sequence of non-space characters.
// The input string does not contain leading or trailing spaces.
// The words are always separated by a single space.
// Try to do it with extra space allocation not more than O(1)

class Solution
{
public:
    static void reverseWordsInString(vector<char> &s);
};

void reverseString(vector<char> &s)
{
    int st = 0;
    int e = s.size() - 1;
    while (st < e)
    {
        swap(s[st++], s[e--]);
    }
}

void reverseEachWord(vector<char>::iterator start, vector<char>::reverse_iterator end, int length)
{
    int mid_index = (length - 1) / 2;
    auto mid_itr = start + mid_index;
    auto mid_rev_itr = end + mid_index;
    advance(mid_itr, 1);
    advance(mid_rev_itr, 1);
    while (start != mid_itr && end != mid_rev_itr)
    {
        swap(*start, *end);
        start++;
        end++;
    }
}

void Solution::reverseWordsInString(vector<char> &s)
{
    // reverse the full string
    reverseString(s);

    // reverse each word from the start
    // vector<char> word;
    int j = 0; // index to know where to advance the start iterator
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            // word.push_back(s[i]);
            continue;
        }
        else {
            // reverseString(word);
            reverseEachWord(s.begin() + j, s.rbegin() + (s.size() - i), abs(i - j)); // (s.size()-1)-(i-1)
            j = i + 1;
            // i++;
            continue;
        }
    }
    // reverse the last word
    reverseEachWord(s.begin() + j, s.rbegin() + (s.size() - i), abs(i - j));
}

int main(int argc, char const *argv[])
{
    // vector<char> s = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    vector<char> s = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ' ', 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 'c', 'o', 'd', 'e'};
    for (auto e : s)
        cout << e;
    cout << endl;
    Solution::reverseWordsInString(s);
    for (auto e : s)
        cout << e;
    cout << endl;
    return 0;
}