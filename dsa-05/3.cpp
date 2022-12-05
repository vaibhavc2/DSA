#include <iostream>
#include <string>
using namespace std;

// using 2-pointer approach for Palindrome:

bool checkPalindrome(string &s)
{
    int st = 0;
    int e = s.length()-1;
    while (st <= e)
    {
        if (s[st] != s[e])
        {
            return false;
        }
        st++;
        e--;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    if (checkPalindrome(str))
    {
        cout << "This string is a palindrome!" << endl;
    }
    
    return 0;
}