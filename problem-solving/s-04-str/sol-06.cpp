#include <iostream>
// #include <vector>
#include <string>
// #include <numeric>
#include <algorithm>
using namespace std;

// Leetcode Q: Remove All Occurrences of a Substring
// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

class Solution {
public:
    // std::string.npos() returns the value when a function fails, here std::string.find() also returns npos() value, so if it doesn't match, proceed forward, else substring not found in the given string
    string removeOccurrences(string s, string part)
    {
        // auto start = s.find(part);
        while (s.find(part) != s.npos)
        {
            // auto start = s.find(part);
            // std::size_t start = s.find(part); // size_t is used for some functions in strings
            // s.erase(s.begin() + start, s.begin() + start + part.length());
            // for more understanding, debugging:
            // auto end = start + part.length();
            // s.erase(s.begin() + start, s.begin() + end); // std::string.erase() erases till one step before the last iterator is given

            // for understanding, std::string.erase() works best with iterators
            // but we can also implement the following:
            s.erase(s.find(part), part.length());
        }
        return s;
    }

    // a better implementation without using string in-built functions, but instead an excellent stack logic implementation:
    string removeOccurrences2(string s, string part);
    // a little bit change in the above algo:
    string removeOccurrences3(string s, string part);

};

// Logic of this algo (removeOccurrences2()):
// We make a copy of our string s (x in code) and then iterate over the string s.
// Now in the current iteration if j is greater than or equal to m that means that we have seen at least m elements, so we can check whether the substring of last m characters is equal to part or not. If it is equal, we reduce the variable 'j' by m showing that we have removed this substring and now we will overwrite the characters from index j.
// Finally we will return the substring of x of length j.
string Solution::removeOccurrences2(string s, string part) {
	string x = s;
	int n = s.size(), m = part.size(), i, j;
	for (i = 0, j = 0; i < n; i++) {
		x[j++] = s[i];
		if (j >= m && x.substr(j - m, m) == part)
			j -= m;
	}
	return x.substr(0, j);
}

// a little alternative to above approach:
// Just reversed the the part variable and adding to new characters to the beginning of the string.. as soon as i find a matching part in the beginning, remove it.. and then reverse final x to get the ans!
string Solution::removeOccurrences3(string s, string part)
{
    string x = "";
    reverse(part.begin(), part.end());
    int n = s.size(), m = part.size(), i;
    for (i = 0; i < n; i++)
    {
        x = s[i] + x;
        if (x.size() >= m && x.substr(0, m) == part)
        {
            x = x.substr(m);
        }
    }
    reverse(x.begin(), x.end());
    return x;
}

int main(int argc, char const *argv[])
{
    // string s = "tyqjskoqvgpujduoxvqaagtttyqjskoqvgpujduoxvqaagtyqjstyqjskoqvgpujduoxvqaagtkoqvgpujduotyqjskoqvgpujduoxvqaagtxvqaagtjgdjx";
    // string s = "rrrzokrrrzoktbgnlerpstimuatbgnlerpstimuagdgtmfy";
    // string s = "ccctltctlltlb";
    string s = "daabcbaabcbc";
    // string s = "axxxxyyyyb";

    // string part = "tyqjskoqvgpujduoxvqaagt";
    // string part = "rrrzoktbgnlerpstimua";
    // string part = "ctl";
    string part = "abc";
    // string part = "xy";

    Solution sol;
    cout << sol.removeOccurrences2(s, part) << endl;

    return 0;
}