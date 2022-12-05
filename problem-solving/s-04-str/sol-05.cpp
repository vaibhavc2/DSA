#include <iostream>
// #include <vector>
#include <string>
// #include <numeric>
using namespace std;

// Q: Replace ' ' with "@40" in the given string
// Donot create new string. Change the given string only
// So this is: 'in-place' solution i.e. extra space should be O(1) space complexity

class Solution
{
public:
    static void replaceSpaces(string &s);
};

void Solution::replaceSpaces(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            // add two slots at the end
            s.push_back(' ');
            s.push_back(' ');

            // shift 'every ch after i' two places ahead
            for (int j = (s.length()-1)-2; j > i; j--)
                s[j+2] = s[j];

            // Put '@40' at the right place
            s[i] = '@';
            s[i+1] = '4';
            s[i+2] = '0';
        }
    }
}

int main(int argc, char const *argv[])
{
    string str;

    cout << "Enter a string: " << endl;
    getline(cin, str);
    cout << endl;

    Solution::replaceSpaces(str);

    cout << "Transformed string: " << endl;
    cout << str << endl;

    return 0;
}