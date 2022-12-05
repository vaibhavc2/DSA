#include <iostream>
// #include <vector>
#include <string>
// #include <numeric>
using namespace std;

// Leetcode Q: Remove All Occurrences of a Substring
// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

class Solution {
private:
    bool checkAns(string &ans, string &part)
    {
        if (ans.length() < part.length())
        {
            return false;
        }
        auto rev_itr = ans.rbegin();
        int count = 0;
        for (int it = part.length() - 1; it >= 0; it--)
        {
            if (part[it] == *rev_itr) count++;
            rev_itr++;
        }
        if (count == part.length())
        {
            return true;
        }
        return false;
    }
public:
    string removeOccurrences(string s, string part)
    {
        string temp, ans;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != part.front())
            {
                ans.push_back(s[i]);
                // check if ans contains the substring 'part' & then remove it
                if (checkAns(ans, part))
                {
                    for (int n = 0; n < part.length(); n++)
                    {
                        ans.pop_back();
                    }
                }
            }
            else
            {
                for (int j = 1; j < part.length(); j++)
                {
                    if (s[i+j] == part[j])
                    {
                        if((j == part.length()-1)) {i += part.length()-1;}
                    }
                    else
                    {
                        ans.push_back(s[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s = "tyqjskoqvgpujduoxvqaagtttyqjskoqvgpujduoxvqaagtyqjstyqjskoqvgpujduoxvqaagtkoqvgpujduotyqjskoqvgpujduoxvqaagtxvqaagtjgdjx";
    // string s = "rrrzokrrrzoktbgnlerpstimuatbgnlerpstimuagdgtmfy";
    // string s = "ccctltctlltlb";
    // string s = "daabcbaabcbc";
    // string s = "axxxxyyyyb";

    string part = "tyqjskoqvgpujduoxvqaagt";
    // string part = "rrrzoktbgnlerpstimua";
    // string part = "ctl";
    // string part = "abc";
    // string part = "xy";

    Solution sol;
    cout << sol.removeOccurrences(s, part) << endl;

    return 0;
}