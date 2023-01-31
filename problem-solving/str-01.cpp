#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Leetcode and Codestudio Q: You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.
// Note :
// String 'S' is NOT case sensitive.

class Solution
{
public:
    static bool checkPalindrome(string);
    static bool checkPalindrome2(string);
    static bool checkPalindrome3(string);
};

bool Solution::checkPalindrome(string s)
{
    int st = 0;
    int e = s.length()-1;

    while (st < e)
    {
        while (!((s[st] >= '0' && s[st] <= '9') || (s[st] >= 'A' && s[st] <= 'Z') || (s[st] >= 'a' && s[st] <= 'z')))
        {
            if (st == e) // in case all chars in string are just symbols!
            {
                return true;
            }   
            st++;
        }

        while (!((s[e] >= '0' && s[e] <= '9') || (s[e] >= 'A' && s[e] <= 'Z') || (s[e] >= 'a' && s[e] <= 'z')))
        {
            e--;
        }
        
        if (tolower(s[st]) != tolower(s[e]))
        {
            return false;
        }

        st++;
        e--;
    }
    
    return true;
}

// can write above code in a cleaner way:
bool Solution::checkPalindrome2(string s) {
    // s.size() is same as s.length()
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        // isalnum() returns 'int'
        while (isalnum(s[i]) == (int)false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == (int)false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }
    
    return true;
}

//* TO CHECK WHY THE FOLLOWING SOLUTION IS NOT ACCEPTED BY LEETCODE AND CODESTUDIO IN SOME TESTCASES, BUT HERE THE CODE PASSES ALL TESTCASES IN VSCODE!
// more optimised and understable simple solution:
bool Solution::checkPalindrome3(string s)
{
    // copy all alphanumeric chars in another string
    string s2;
    for (int i = 0; i < s.size(); i++)
    {
        // isalnum() returns 'int', but no need to convert to bool
        if ((isalnum(s[i])))
        {
            s2.push_back(s[i]);
        }
    }

    // no need of this:
    // convert all to lowercase
    // transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    
    // compare now using 2-pointer approach
    int i = 0;
    int j = s2.length() - 1;
    while (i < j)
    {
        if (tolower(s2[i]) != tolower(s2[j]))
        {
            return 0;
        }
        i++;
        j--;
    }
    
    return 1;
}

int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s); // this accepts " " i.e. empty space as well

    // string str = adjustString(s);
    // cout << "Adjusted string: " << str << endl;
    // cout << "Reverse of the adjusted string: " << reverseString(str) << endl;

    if (Solution::checkPalindrome3(s))
    {
        cout << "This string is a palindrome!" << endl;
    }
    string str = "vaibhav";
    cout << str.size() << " " << str.length() << endl;
    str.push_back('\0');
    cout << str.size() << " " << str.length() << endl;

    return 0;
}